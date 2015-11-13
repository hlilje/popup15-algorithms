#include "crt.hpp"
#include <iostream>

using ll = long long;


ll mul_inv(ll a, ll b)
{
    ll b0 = b;
    ll x0 = 0;
    ll x1 = 1;

    if (b == 1) return 1;

    while (a > 1)
    {
        ll q = a / b;
        ll t = b;
        b = a % b;
        a = t;
        t = x0;
        x0 = x1 - (q * x0);
        x1 = t;
    }

    if (x1 < 0) x1 = x1 + b0;

    return x1;
}

ll crt(const ll a, const ll n, const ll b, const ll m, const ll K)
{
    ll res = 0;

    ll inv = mul_inv(m, n);
    res += a * inv * m;

    inv = mul_inv(n, m);
    res += b * inv * n;

    return res % K;
}
