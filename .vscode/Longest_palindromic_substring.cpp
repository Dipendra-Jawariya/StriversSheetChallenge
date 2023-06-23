
string longestPalinSubstring(string str)
{
    int st = 0;
    int len = 1;
    int low ,high;
    int n = str.size();
    for(int i = 1; i < n ;i++) {
        low = i-1;
        high = i;
        while(low >= 0 && high < n && str[low] == str[high])    {
           if(high - low +1 > len ){
            st = low;
            len = high-low + 1;
            }
            low--;
            high++;
        }
        //odd case
        low = i-1;
        high = i+1;
        while(low >= 0 && high < n && str[low] == str[high]) {
            if(high - low + 1 > len)  {
                st = low;
                len = high - low + 1;
            }
            low--;
            high++;
        }
    }
    return str.substr(st,len);
}