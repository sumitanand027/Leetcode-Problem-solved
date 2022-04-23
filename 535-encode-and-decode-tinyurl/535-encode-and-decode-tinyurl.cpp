class Solution
{
public:
    string choices = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    map<string, string> mp;
    string initial = "http://tinyurl.com";

    string encode(string longUrl)
    {
        string random = "";

       while (mp.find(random) != mp.end())
        {
            char ch = choices[rand() % 62]; 
            random += ch;

        }


        string shortUrl = initial + random;

        mp[shortUrl] = longUrl;
 
        return shortUrl;
    }

    string decode(string shortUrl)
    {
        return mp[shortUrl];
    }
};