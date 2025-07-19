class Solution:
    def profitableSchemes(self, n: int, minProfit: int, group: List[int], profit: List[int]) -> int:
        MOD = 10**9 + 7
        dp = [[0] * (n + 1) for _ in range(minProfit + 1)]
        dp[0][0] = 1
        for p_i, g_i in zip(profit, group):
            for p in range(minProfit, -1, -1):
                for g in range(n, g_i - 1, -1):
                    novo_p = min(p + p_i, minProfit)
                    dp[novo_p][g] = (dp[novo_p][g] + dp[p][g - g_i]) % MOD
        total_schemes = sum(dp[minProfit]) % MOD
        
        return total_schemes
