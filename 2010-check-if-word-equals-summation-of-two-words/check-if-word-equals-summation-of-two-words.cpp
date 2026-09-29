class Solution {
public:
   int isValue(string s){
    int num =0;
    for(int i=0;i<s.size();i++){
        int digit=s[i]-'a';
        num=num*10+digit;
    }
    return num;
   }

    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int a= isValue(firstWord);
        int b= isValue(secondWord);
        int c=isValue(targetWord);
        return a+b==c;
        
    }
};