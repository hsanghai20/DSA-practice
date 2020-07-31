// Link: https://leetcode.com/problems/compare-version-numbers/

// solution:
    int compareVersion(string version1, string version2) {
        string ver1="";
        string ver2="";
        for(int i=0;i<version1.length();i++)
        {
            if(version1[i]=='.')
                ver1+=' ';
            else
                ver1+=version1[i];
        }
        for(int i=0;i<version2.length();i++)
        {
            if(version2[i]=='.')
                ver2+=' ';
            else
                ver2+=version2[i];
        }
        int x=0,y=0;
        int ans=0;
        int count1=0;
        int count2=0;
        stringstream s3(ver1);
        stringstream s4(ver2);
        while(s3>> x)
        {
            count1++;
        }
        while(s4>> y)
            count2++;
        stringstream s1(ver1);
        stringstream s2(ver2);
        x=0;
        y=0;
        int q=min(count1,count2);
        while(q--)
        {
            s1 >> x;
            s2 >> y;
            // cout << x << " " << y << endl;
            if(x>y)
            {
                ans=1;
                break;
            }
            else if(y>x)
            {
                ans=-1;
                break;
            }
        }
        if(ans==0)
        {
            if(count1>count2)
            {
                int e=count1-count2;
                while(e--)
                {
                    s1 >> x;
                    if(x!=0)
                    {
                        ans=1;
                        break;
                    }
                }   
            }
            else if(count2>count1)
            {
                int e=count2-count1;
                while(e--)
                {
                    s2 >> y;
                    if(y!=0)
                    {
                        ans=-1;
                        break;
                    }
                }   
            }
        }
        return ans;
    }
