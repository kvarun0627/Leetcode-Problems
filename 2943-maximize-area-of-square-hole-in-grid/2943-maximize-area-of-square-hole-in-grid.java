class Solution {
    public int maximizeSquareHoleArea(int n, int m, int[] hBars, int[] vBars)
    {
        Arrays.sort(hBars);
        Arrays.sort(vBars);

        int l=hBars.length;
        int r=vBars.length;

        int[] lcsH = new int[l];
        lcsH[0] = 1;
        int maxH=1;
        for(int i=1;i<l;i++)
        {
            if(hBars[i]==hBars[i-1]+1)
            {
                lcsH[i]=lcsH[i-1]+1;
            }
            else
            {
                lcsH[i]=1;
            }
            maxH=Math.max(maxH,lcsH[i]);
        }

        int[] lcsV= new int [r+1];
        lcsV[0]=1;
        int maxV=1;
        for(int j=1;j<r;j++)
        {
            if(vBars[j]==vBars[j-1]+1)
            {
                lcsV[j]=lcsV[j-1]+1;
            }
            else
            {
                lcsV[j]=1;
            }
            maxV=Math.max(maxV,lcsV[j]);
        }

        int mini=Math.min(maxV,maxH);
        return (mini+1)*(mini+1);
    }
}