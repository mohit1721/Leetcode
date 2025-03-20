class Solution {
public:
    int replace(int n)
    {
        int num=0;
        while(n>0)
        {
            int rem= n%10;
            num+=rem*rem;
            n/=10;
        }
        return num;
    }
// Happy number ke liye cyclic pattern se bachne ke liye, hum ek set ka use karenge jo numbers ko track karega, taaki agar koi number dobara aaye, toh hum loop ko break kar sakein.
    bool isHappy(int n) {
        if(n<0) return false;
          unordered_set<int> visited;
      
    //  while(n!=1 && !visited.count(n) ){
    //     visited.insert(n);
    //     n=replace(n);
      
    //  }
        
    
    // return n==1;


// # 2 ptr
int slow = n, fast = n;
        do {
            slow = replace(slow);
            fast = replace(replace(fast));
            if(fast == 1) return 1;
        } while(slow != fast);
        return 0;

    }
};