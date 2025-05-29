### Subset Sum 3 CC:


This C++ program checks, for each test case, whether there exists a **non-empty subsequence** of the input array whose sum is divisible by 3. Let's walk through the code and its logic in detail.

---

### ✅ **What the program does:**

* For each test case:

  * It reads an array of integers.
  * It uses **dynamic programming** to determine if there exists **a non-empty subsequence** of the array such that the **sum of that subsequence is divisible by 3**.
  * If such a subsequence exists, it prints `Yes`; otherwise, it prints `No`.

---

### 🔍 **Line-by-line breakdown:**

```cpp
int T; 
cin >> T;
```

* Reads the number of test cases.

---

```cpp
while (T--) {
    int N; 
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
```

* For each test case:

  * Reads the number of elements `N`.
  * Reads the array `A` of size `N`.

---

```cpp
bool dp[3] = {false, false, false};
```

* `dp[i]` means: **Is there a subsequence (possibly not contiguous) whose sum mod 3 is `i`?**
* Initially, all are false (no subsequences considered yet).

---

```cpp
for (int i = 0; i < N; ++i) {
    bool new_dp[3];
    for (int j = 0; j < 3; ++j) new_dp[j] = dp[j];
```

* For each number in the array:

  * Copy the current state of `dp` to `new_dp`. We'll update `new_dp` based on the current number.

---

```cpp
    int mod_val = A[i] % 3;
    new_dp[mod_val] = true;
```

* A single-element subsequence (just `A[i]`) has sum mod 3 equal to `mod_val`. Mark that as achievable.

---

```cpp
    for (int j = 0; j < 3; ++j) {
        if (dp[j]) {
            int nxt = (j + mod_val) % 3;
            new_dp[nxt] = true;
        }
    }
```

* If there was already a subsequence with sum mod 3 = `j`, and we add `A[i]` to it, then we can achieve `(j + mod_val) % 3`.
* So, we mark `new_dp[nxt]` as achievable.

---

```cpp
    for (int j = 0; j < 3; ++j) dp[j] = new_dp[j];
}
```

* Update `dp` for the next iteration.

---

```cpp
cout << (dp[0] ? "Yes\n" : "No\n");
```

* Finally, check if we have a subsequence whose sum mod 3 is 0 (i.e., divisible by 3).
* If yes, print `"Yes"`, else `"No"`.

---

### 🧠 Example:

Suppose the input is:

```
1
3
2 1 4
```

The possible subsequence sums are:

* `2` → 2 % 3 = 2
* `1` → 1 % 3 = 1
* `4` → 4 % 3 = 1
* `2 + 1` = 3 → 3 % 3 = 0 ✅
* `2 + 4` = 6 → 0 ✅
* `1 + 4` = 5 → 2
* `2 + 1 + 4` = 7 → 1

So `Yes` is the correct output.

---

### ⚙️ Summary:

This is an efficient dynamic programming solution using modulo 3 properties to track reachable subsequence sums, and it answers whether there's **any non-empty subsequence** whose sum is divisible by 3.
