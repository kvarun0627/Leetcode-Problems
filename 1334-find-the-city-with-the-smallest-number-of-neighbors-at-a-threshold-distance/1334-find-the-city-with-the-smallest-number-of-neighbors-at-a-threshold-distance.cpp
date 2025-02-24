class Solution {
public:
    int floyd_warshall(int n,int distanceThreshold,vector<vector<int>>&distance)
    {
        for(int via=0;via<n;via++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(distance[i][via]==INT_MAX || distance[via][j]==INT_MAX) continue;

                    distance[i][j]=min(distance[i][j],distance[i][via] + distance[via][j]);
                }
            }
        }
        int total_cities=n;
        int city_no=-1;
        for(int i=0;i<n;i++)
        {
            int cnt=0;
            for(int j=0;j<n;j++)
            {
                if(i!=j && distance[i][j]<=distanceThreshold)
                {
                    cnt++;
                }
            }
            if(cnt<=total_cities)
            {
                total_cities=cnt;
                city_no=i;
            }
        }
        return city_no;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>distance(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++)
        {
            distance[i][i]=0;
        }
        for(vector<int>e:edges)
        {
            distance[e[0]][e[1]]=e[2];
            distance[e[1]][e[0]]=e[2];
        }
        return floyd_warshall(n,distanceThreshold,distance);
    }
};