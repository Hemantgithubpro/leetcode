Here are structured notes on modulo inverse, focusing on the concepts, algorithms, and implementations most relevant for competitive programming.

## Modulo Inverse in Competitive Programming

In modular arithmetic, division is not as straightforward as addition, subtraction, or multiplication. To compute $(a / b) \pmod{m}$, you cannot simply divide $a$ by $b$. Instead, you must multiply $a$ by the **modulo multiplicative inverse** of $b$.

### 1. Definition and Existence

The modulo inverse of an integer $a$ modulo $m$ is an integer $x$ such that:


$$a \cdot x \equiv 1 \pmod{m}$$


The inverse $x$ is often denoted as $a^{-1}$.

**Existence:** The modulo inverse of $a$ modulo $m$ exists **if and only if** $a$ and $m$ are coprime, meaning $\gcd(a, m) = 1$.

---

### 2. Method 1: Fermat's Little Theorem (The CP Standard)

This is the most common method used in competitive programming because modulo values are frequently prime numbers (like $10^9 + 7$ or $998244353$).

Fermat's Little Theorem states that if $m$ is a prime number and $a$ is not divisible by $m$:


$$a^{m-1} \equiv 1 \pmod{m}$$

By splitting the powers, we get:


$$a \cdot a^{m-2} \equiv 1 \pmod{m}$$

Therefore, the modulo inverse is:


$$a^{-1} \equiv a^{m-2} \pmod{m}$$

**Implementation:** You can compute this efficiently in $O(\log m)$ time using binary exponentiation.

```cpp
// Binary Exponentiation to calculate (base^exp) % mod
long long power(long long base, long long exp, long long mod) {
    long long res = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

// Modulo Inverse using FLT
long long modInverse(long long n, long long mod) {
    return power(n, mod - 2, mod);
}

```

---

### 3. Method 2: Extended Euclidean Algorithm

When the modulo $m$ is **not prime**, Fermat's Little Theorem cannot be used. However, if $\gcd(a, m) = 1$, you can use the Extended Euclidean Algorithm (EEA).

EEA finds integer coefficients $x$ and $y$ for the equation:


$$a \cdot x + m \cdot y = \gcd(a, m)$$

Since $\gcd(a, m) = 1$, the equation becomes:


$$a \cdot x + m \cdot y = 1$$

Taking modulo $m$ on both sides:


$$a \cdot x \equiv 1 \pmod{m}$$

Here, $x$ is the modulo inverse.

**Implementation:** This also runs in $O(\log(\min(a, m)))$ time.

```cpp
// Extended Euclidean Algorithm
long long extGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long d = extGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

// Modulo Inverse using EEA
long long modInverse(long long a, long long m) {
    long long x, y;
    long long g = extGCD(a, m, x, y);
    if (g != 1) {
        return -1; // Inverse doesn't exist
    } else {
        // x might be negative, so add m and take modulo
        return (x % m + m) % m; 
    }
}

```

---

### 4. Method 3: Linear Time Inverse for a Range

Sometimes you need the modulo inverse for all numbers from $1$ to $n$ modulo a prime $m$ (e.g., when precomputing factorials for combinatorics). Calculating them one by one takes $O(n \log m)$. You can do it in $O(n)$ time using the following recurrence:

$$inv[i] = \left(m - \lfloor\frac{m}{i}\rfloor \cdot inv[m \pmod{i}] \right) \pmod{m}$$

**Implementation:**

```cpp
vector<long long> inv(n + 1);
inv[1] = 1;
for (int i = 2; i <= n; ++i) {
    inv[i] = m - (m / i) * inv[m % i] % m;
}

```

---

### Common Pitfalls to Avoid

* **Division before Modulo:** Never do `(A / B) % MOD`. Always do `(A % MOD * modInverse(B, MOD)) % MOD`.
* **Negative Values:** Operations like EEA can return a negative inverse. Always normalize it by using `(x % mod + mod) % mod`.
* **Checking Coprimality:** If using the EEA method, always verify that the returned GCD is exactly $1$ before attempting to use the inverse value.


Calculating combinations, often denoted as $nCr$ or $\binom{n}{r}$, modulo a large prime is one of the most frequent tasks in competitive programming combinatorics.

Since $nCr = \frac{n!}{r!(n-r)!}$, division modulo $m$ requires multiplying by the modulo inverse of the denominator.

By precomputing factorials and their inverses, you can answer any $nCr$ query in **$O(1)$ time**.

### The Mathematical Formula

Under modulo $m$, the formula transforms into:


$$\binom{n}{r} \equiv n! \cdot (r!)^{-1} \cdot ((n-r)!)^{-1} \pmod{m}$$

Where $(x!)^{-1}$ is the modulo inverse of $x!$.

### The Precomputation Strategy

You could calculate the modulo inverse for every factorial individually, but that takes $O(N \log m)$ time. A smarter, standard CP approach computes all inverse factorials in **$O(N)$ time** after a single $O(\log m)$ operation.

1. **Compute Factorials:** Iteratively compute $fact[i] = (fact[i-1] \cdot i) \pmod{m}$ up to your maximum constraint (e.g., $MAXN$).
2. **Compute the Last Inverse:** Use Fermat's Little Theorem to find the modulo inverse of the *largest* factorial, $fact[MAXN]$. Store this in $invFact[MAXN]$.
3. **Compute Remaining Inverses Backwards:** Use the mathematical property that $\frac{1}{(i-1)!} = \frac{1}{i!} \cdot i$. In modulo terms:

$$invFact[i-1] = (invFact[i] \cdot i) \pmod{m}$$



You iterate backwards from $MAXN$ to $0$ filling the array.

### C++ Implementation

Here is a robust template you can drop into your CP library:

```cpp
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1000000; // Adjust based on problem constraints

long long fact[MAXN + 1];
long long invFact[MAXN + 1];

// Standard binary exponentiation
long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

// Precomputes factorials and inverse factorials in O(MAXN)
void precompute() {
    fact[0] = 1;
    for (int i = 1; i <= MAXN; ++i) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    // Fermat's Little Theorem for the largest inverse factorial
    invFact[MAXN] = power(fact[MAXN], MOD - 2);

    // Compute the rest backwards
    for (int i = MAXN - 1; i >= 0; --i) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

// O(1) query function
long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0; // Base cases
    
    // n! * (r!)^-1 % MOD
    long long num = (fact[n] * invFact[r]) % MOD;
    
    // (n! * (r!)^-1) * ((n-r)!)^-1 % MOD
    return (num * invFact[n - r]) % MOD;
}

int main() {
    // 1. Always call precompute() once at the start of your program
    precompute();

    // 2. Answer queries in O(1)
    int n = 10, r = 3;
    cout << n << "C" << r << " % " << MOD << " = " << nCr(n, r) << "\n";

    return 0;
}

```

### Complexity Breakdown

* **Time Complexity (Precomputation):** $O(N)$ to build the factorial array, $O(\log m)$ to inverse the largest factorial, and $O(N)$ to build the inverse factorial array backwards. Total time: $O(N + \log m)$.
* **Time Complexity (Query):** $O(1)$ per query.
* **Space Complexity:** $O(N)$ to store the `fact` and `invFact` arrays.

# Lucas Theorem
- It is used to compute nCr % p when p is a prime and n, r can be very large (up to 10^18).
Here is a breakdown of Lucas' Theorem, which is your go-to tool when the constraints get extreme.

In competitive programming, you'll sometimes see problems where $n$ and $r$ are up to $10^{18}$, but the modulo $m$ (let's call it $p$ because it must be prime) is relatively small, like $10^5$. You can't precompute factorials up to $10^{18}$ because you'd run out of both time and memory.

### The Core Concept: Base $p$ Representation

You are likely very familiar with converting numbers into base 2 (binary). Lucas' Theorem relies on that exact same fundamental concept, but instead of base 2, you convert $n$ and $r$ into **base $p$** (where $p$ is your prime modulo).

If we express $n$ and $r$ in base $p$, they look like this:


$$n = n_k p^k + n_{k-1} p^{k-1} + \dots + n_1 p + n_0$$

$$r = r_k p^k + r_{k-1} p^{k-1} + \dots + r_1 p + r_0$$

*(Here, $n_i$ and $r_i$ are just the digits of $n$ and $r$ in base $p$, meaning $0 \le n_i, r_i < p$)*

### Lucas' Theorem Formula

The theorem states that the massive combination $\binom{n}{r} \pmod{p}$ is simply the product of the combinations of their individual base $p$ digits:

$$\binom{n}{r} \equiv \prod_{i=0}^k \binom{n_i}{r_i} \pmod{p}$$

**The Magic Rule:** If any base $p$ digit of $r$ is strictly greater than the corresponding digit of $n$ (i.e., $r_i > n_i$), then $\binom{n_i}{r_i} = 0$. Because everything is multiplied together, the entire answer instantly becomes $0$.

### Why this is incredibly fast

Instead of dealing with $10^{18}$, you are now only calculating $\binom{n_i}{r_i}$. Because $n_i$ and $r_i$ are digits in base $p$, they are strictly less than $p$. If $p = 10^5$, you only need to precompute factorials up to $10^5$, which easily fits in memory and time!

### C++ Implementation

We can implement this elegantly using recursion. Just like extracting the last digit of a number using `% 10` and dropping it using `/ 10`, we extract the base $p$ digits using `% p` and `/ p`.

```cpp
#include <iostream>
#include <vector>

using namespace std;

// Assuming p is small enough (e.g., 10^5) to precompute factorials
const int MAXP = 100005; 
long long fact[MAXP];
long long invFact[MAXP];

// Standard binary exponentiation
long long power(long long base, long long exp, long long p) {
    long long res = 1;
    base %= p;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % p;
        base = (base * base) % p;
        exp /= 2;
    }
    return res;
}

// Precompute factorials up to p
void precompute(long long p) {
    fact[0] = 1;
    for (int i = 1; i < p; ++i) {
        fact[i] = (fact[i - 1] * i) % p;
    }
    
    invFact[p - 1] = power(fact[p - 1], p - 2, p);
    for (int i = p - 2; i >= 0; --i) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % p;
    }
}

// O(1) nCr for small numbers (less than p)
long long small_nCr(long long n, long long r, long long p) {
    if (r < 0 || r > n) return 0;
    long long num = (fact[n] * invFact[r]) % p;
    return (num * invFact[n - r]) % p;
}

// Lucas Theorem Implementation O(log_p(n))
long long lucas(long long n, long long r, long long p) {
    if (r == 0) return 1; // Base case
    
    // Extract last base-p digits
    long long ni = n % p;
    long long ri = r % p;
    
    // If a digit of r is greater than n, the whole product is 0
    if (ri > ni) return 0; 
    
    // Multiply the current digit's nCr with the recursive call for the rest
    return (small_nCr(ni, ri, p) * lucas(n / p, r / p, p)) % p;
}

int main() {
    long long p = 100003; // A small prime
    precompute(p);
    
    long long n = 1e18; // Massive n
    long long r = 5e17; // Massive r
    
    cout << "nCr % p = " << lucas(n, r, p) << "\n";
    return 0;
}

```

### Complexity Breakdown

* **Time Complexity:** * **Precomputation:** $O(p)$ to precompute factorials up to $p$.
* **Query:** $O(\log_p n)$ to recursively strip away the base $p$ digits. This is practically instantaneous.


* **Space Complexity:** $O(p)$ to store the factorial and inverse factorial arrays.
