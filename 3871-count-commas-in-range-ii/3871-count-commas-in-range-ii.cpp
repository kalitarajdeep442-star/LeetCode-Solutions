class Solution {
public:
    long long countCommas(long long n) {
        if(n<=999)  return 0;
        if(n<=999999)   return n-999;
        if(n<=999999999)    return (n-999999)*2+999000;
        if(n<=999999999999) return (n-999999999)*3+999000000*2+999000;
        if(n<=999999999999999)  return (n-999999999999)*4+999000000000*3+999000000*2+999000;
        return (n-999999999999)*4+999000000000*3+999000000*2+999000+1;
    }
};