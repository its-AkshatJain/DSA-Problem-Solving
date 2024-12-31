// Very IMP
void computeLPS(string pattern, vector<int>& lps) {
    int M = pattern.length();
    int len = 0; // Length of the previous longest prefix & suffix

    lps[0] = 0; // First element is always 0

    int i = 1;
    while (i < M) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1]; // Go back in the LPS array
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

vector<int> search(string pat, string txt) {
    int M = pat.length();
    int N = txt.length();
    vector<int> result;

    // Create the LPS array
    vector<int> lps(M, 0);  //longest prefix and suffix equal
    computeLPS(pat, lps);

    int i = 0; // Index for text
    int j = 0; // Index for pattern

    while (i < N) {
        if (pat[j] == txt[i]) {
            i++;
            j++;
        }

        if (j == M) {
            result.push_back(i - j); // Pattern found, 0-based index
            j = lps[j - 1];
        } else if (i < N && pat[j] != txt[i
        ++]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    return result;
}