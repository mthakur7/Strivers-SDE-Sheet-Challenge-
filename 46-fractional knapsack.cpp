#include <bits/stdc++.h> 
bool compare(pair <int, int> a, pair <int, int> b)
{   
	double r1 = (double) a.second / a.first;
    double r2 = (double) b.second / b.first;

    return r1 > r2;
}


double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    sort(items.begin(), items.end(), compare);
    int currWt=0;
    double ans=0.00;
    for(int i=0;i<n;i++){
        if(currWt+items[i].first<=w){
            currWt+=items[i].first;
            ans+=items[i].second;
        }
        else{
            int remWt=w-currWt;
            ans+=(double)items[i].second*((double)remWt/items[i].first);
            break;
        }
    }
    return ans;
}
