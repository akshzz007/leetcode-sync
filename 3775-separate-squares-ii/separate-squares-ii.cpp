#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Event {
        long long y;
        int x1, x2;
        int type; // +1 = add, -1 = remove
        bool operator<(const Event& other) const {
            return y < other.y;
        }
    };

    struct SegmentTree {
        int n;
        vector<long long> cover;   // cover count
        vector<long long> length;  // covered length
        vector<long long> xs;

        SegmentTree(const vector<long long>& xcoords) {
            xs = xcoords;
            n = xs.size() - 1;
            cover.assign(4 * n, 0);
            length.assign(4 * n, 0);
        }

        void pull(int node, int l, int r) {
            if (cover[node] > 0) {
                length[node] = xs[r + 1] - xs[l];
            } else if (l == r) {
                length[node] = 0;
            } else {
                length[node] = length[node * 2] + length[node * 2 + 1];
            }
        }

        void update(int node, int l, int r, int ql, int qr, int val) {
            if (qr < l || r < ql) return;
            if (ql <= l && r <= qr) {
                cover[node] += val;
                pull(node, l, r);
                return;
            }
            int mid = (l + r) / 2;
            update(node * 2, l, mid, ql, qr, val);
            update(node * 2 + 1, mid + 1, r, ql, qr, val);
            pull(node, l, r);
        }

        void update(int l, int r, int val) {
            if (l <= r)
                update(1, 0, n - 1, l, r, val);
        }

        long long query() {
            return length[1];
        }
    };

    double separateSquares(vector<vector<int>>& squares) {
        vector<Event> events;
        vector<long long> xs;

        // Build events
        for (auto &sq : squares) {
            long long x = sq[0], y = sq[1], l = sq[2];
            events.push_back({y, 0, 0, +1});
            events.push_back({y + l, 0, 0, -1});
            xs.push_back(x);
            xs.push_back(x + l);
        }

        // Coordinate compression
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());

        for (int i = 0; i < squares.size(); i++) {
            long long x = squares[i][0];
            long long l = squares[i][2];

            int L = lower_bound(xs.begin(), xs.end(), x) - xs.begin();
            int R = lower_bound(xs.begin(), xs.end(), x + l) - xs.begin() - 1;

            events[2 * i].x1 = L;
            events[2 * i].x2 = R;
            events[2 * i + 1].x1 = L;
            events[2 * i + 1].x2 = R;
        }

        sort(events.begin(), events.end());

        // ---------- First sweep: total union area ----------
        SegmentTree st(xs);
        long long totalArea = 0;
        long long prevY = events[0].y;

        for (auto &e : events) {
            long long dy = e.y - prevY;
            totalArea += st.query() * dy;
            st.update(e.x1, e.x2, e.type);
            prevY = e.y;
        }

        double target = totalArea / 2.0;

        // ---------- Second sweep: find y ----------
        SegmentTree st2(xs);
        double currArea = 0;
        prevY = events[0].y;

        for (auto &e : events) {
            long long dy = e.y - prevY;
            double covered = st2.query();

            if (covered > 0 && currArea + covered * dy >= target) {
                double need = (target - currArea) / covered;
                return prevY + need;
            }

            currArea += covered * dy;
            st2.update(e.x1, e.x2, e.type);
            prevY = e.y;
        }

        return prevY; // fallback
    }
};
