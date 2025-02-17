class Solution {
public:
    unordered_set<string> s;
    string a="";
    int numTilePossibilities(string tiles) {
        
        sort(tiles.begin(),tiles.end());
        subsequence(0,tiles);
        
        int cnt=0;
        
        for(auto x:s)
        {
            string g=x;
            do{
                if(g=="")
                {
                    break;
                }
                
                cnt++;
                
            }while(next_permutation(g.begin(),g.end()));
            
        }
        
        return cnt;
    }
    
    void subsequence(int index,string tiles)
    {
        s.insert(a);
        
        for(int i=index;i<tiles.size();i++)
        {
            a=a+tiles[i];
            subsequence(i+1,tiles);
            a.pop_back();
        }
    }
};