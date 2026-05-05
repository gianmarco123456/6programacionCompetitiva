#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    int caseNum = 1;

    while (cin >> N >> Q && (N != 0 || Q != 0)) {
        vector<int> marbles(N);

        // Leer los mármoles
        for (int i = 0; i < N; i++) {
            cin >> marbles[i];
        }

        // Ordenar los mármoles
        sort(marbles.begin(), marbles.end());

        cout << "CASE# " << caseNum++ << ":\n";

        // Procesar consultas
        while (Q--) {
            int x;
            cin >> x;

            // Buscar primera aparición con lower_bound
            auto it = lower_bound(marbles.begin(), marbles.end(), x);

            if (it != marbles.end() && *it == x) {
                int pos = (it - marbles.begin()) + 1; // posición desde 1
                cout << x << " found at " << pos << "\n";
            } else {
                cout << x << " not found\n";
            }
        }
    }

    return 0;
}
