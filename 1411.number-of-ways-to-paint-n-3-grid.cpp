/*
 * @lc app=leetcode id=1411 lang=cpp
 *
 * [1411] Number of Ways to Paint N × 3 Grid
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * 풀이 자체는 어려울 것 같지 않은데, 완전 탐색으로 풀면 시간 복잡도가
 * O((3n)^3)이라 쉽지 않을 것 같음. DP를 적용하고, 모듈러 연산시에 오버플로우에
 * 조심해야겠음.
 * 템플릿에 인자로 주어진건 n인데 n이 1 증가함에 따른 패턴이 있는지도 관찰해 볼
 * 법 함.
 * - n=1, 3일 때는 3*2*2 = 12
 * - n=2, 6일 때는 3*2^5 = 96
 * - n=3, 9일 때는 3*2^8...
 * - 일반화된 식은 3*2^(3n-1)
 * 그러면 굳이 완전 탐색을 하지말고 이걸 어떻게 오버플로우 없이 계산할 수 있을지
 * 생각해봐야 할 것 같음 모듈러 연산의 특징은.. 뭐가 있더라.. (a+b) % c =
 * ((a%c)+(b%c))%c
 * (a*b) % c에 관한 특징이 있으면 좋을 것 같은데..
 * 12 % (10^9+7) = 12
 * 3%~ * 2%~ * 2%~ = 12
 * 똑같지 않을까???
 *
 * -> 문제 이해를 잘못함. 3n 길이가 아니라 3 by n 그리드임.
 * 경우의 수가 두 개 생기는데.. 좌측과 위의 셀이 같을 때와 다를 때
 * ABC(ACB, BAC, BCA, CAB, CBA) -> BAB, BCB, CAB, BCA // 6 * (2 + 2)
 * ABA -> BAC, BAB, BCB, CAC, CAB // 6 * (3 + 2)
 * 따라서 2줄 일 때는 6*(2+2) + 6*(3+2)
 * 3줄이 되면,,,
 * 6*(2*(3+2) + 2*(1+1)) + 6*(3*(3+2)+2*(1+1))
 *  */
// @lc code=start
class Solution {
 public:
  int numOfWays(int n) {
    long long ret1 = 6;  // ABC
    long long ret2 = 6;  // ABA
    int mod = 1000000007;
    for (int i = 0; i < n - 1; ++i) {
      long long tmp1 =
          ((2 * (ret1 % mod) % mod) + (2 * (ret2 % mod) % mod)) % mod;
      long long tmp2 =
          ((2 * (ret1 % mod) % mod) + (3 * (ret2 % mod) % mod)) % mod;

      ret1 = tmp1;
      ret2 = tmp2;
    }

    return (int)((ret1 % mod) + (ret2 % mod)) % mod;
  }
};
// @lc code=end
