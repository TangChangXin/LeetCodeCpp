//
// Created by XKA on 2021/8/30. 简单 x 的平方根
//

class Solution69 {
public:
    //第一次做
    int mySqrt(int x) {
        int z左边界 = 0, y右边界 = x, p平方根 = z左边界 + (y右边界-z左边界)/2; //防止溢出
        //注意结束条件
        while (z左边界 <= y右边界){
            if ((long long)p平方根*p平方根 == x) return p平方根; //(long long)防止整型溢出
            else if ((long long)p平方根*p平方根 > x) {
                y右边界 = p平方根-1;
                p平方根 = z左边界 + (y右边界-z左边界)/2;
            } else{
                z左边界 = p平方根+1;
                p平方根 = z左边界 + (y右边界-z左边界)/2;
            }
        }
        return y右边界; //算一下就懂了
    }

    //todo 牛顿迭代法
};