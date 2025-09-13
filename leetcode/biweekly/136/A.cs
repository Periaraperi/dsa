public class A 
{
    public int WinningPlayerCount(int n, int[][] pick) 
    {
        int maxColor = pick.Select(e => e[1]).ToList().Max()+1;
        int[,] lst = new int[n, maxColor];

        for (int i=0; i<pick.Length; ++i)
        {
            var x = pick[i][0];
            var y = pick[i][1];
            ++lst[x, y];
        }

        int ans = 0;
        for (int i=0; i<n; ++i)
        {
            for (int j=0; j<maxColor; ++j)
            {
                if (lst[i, j] >= i+1)
                {
                    ++ans;
                    break;
                }
            }
        }

        return ans;
    }
}
