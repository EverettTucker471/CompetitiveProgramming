#include <bits/stdc++.h>

using namespace std;

/**
 * Helper function for constructing the suffix array
 * @param s the string to evaluate
 * @return a sorted vector of suffix starting positions
 */
vector<int> sort_cyclic_shifts(string const& s) {
    int n = s.size();
    const int alphabet = 256;
    vector<int> p(n);  // Sorted offsets
    vector<int> c(n);  // Equivalence Classes
    vector<int> cnt(max(alphabet, n), 0);  // Counts for each character

    // Sorting length-1 cyclic substrings
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i - 1];
    // Sorting offsets by frequency
    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;

    // Assigning equivalence classes
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i - 1]]) {
            classes++;
        }
        c[p[i]] = classes - 1;
    }

    vector<int> pn(n), cn(n);  // Temporary vectors for second elements
    for (int h = 0; (1 << h) < n; ++h) {
        // Lookup second ordering from table
        for (int i = 0; i < n; i++) {
            pn[i] = (p[i] - (1 << h) + n) % n;
        }

        // Sorting based on second ordering (pn)
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++) 
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        
        // Creating equivalence classes for the new 2-element ordering
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << h)) % n]};
            if (cur != prev) ++classes;
            cn[p[i]] = classes - 1;
        }
        
        c.swap(cn);  // Copying equivalance classes over
    }

    return p;
}

/**
 * Constructs a suffix array for the string s:
 * A list of suffix offsets [0, n - 1] sorted alphabetically
 * @param s the string to construct a suffix array for
 */
vector<int> construct_suffix_array(string s) {
    s += '$';
    vector<int> sorted_shifts = sort_cyclic_shifts(s);
    sorted_shifts.erase(sorted_shifts.begin());
    return sorted_shifts;
}

