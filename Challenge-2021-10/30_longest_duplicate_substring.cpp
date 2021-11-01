#include "../header.h"

class Solution {
public:
    string longestDupSubstring(string s) {
        //初始操作，新建各种数组等
        int length = s.length();
        vector<int> nums(length, 0);
        vector<int> rank(length, 0);
        for(int i = 0; i < length; i++){
            nums[i] = s[i] - 'a' + 1;
            rank[i] = s[i] - 'a' + 1;
        }

        //求rank数组，isOk检查当前rank数组是否已经收敛
        bool isOk = false;
        for(int step = 1; step/2 < length && !isOk; step *= 2){
            isOk = getRank(rank, step);
        }
        //逆操作从rank求sa
        vector<int> sa(length, 0);
        for(int i = 0; i < length; i++){
            sa[rank[i]-1] = i+1;
        }
        //rank和sa结合求height
        vector<int> height = getHeight(nums, rank, sa);
        //遍历height求最长重复子串
        int max = 1;
        string result = "";
        for(int i = 0; i < length; i++){
            if(height[i] >= max){
                max = height[i];
                result = s.substr(sa[i]-1, height[i]);
            }
        }
        return result;
    }

    bool getRank(vector<int>& nums, int step){
        //假设输入nums = [1,1,2,1,1,1,1,2]，step = 1，则相当于对以下数字对进行排序：<1,1>,<1,2>,<2,1>,<1,1>,<1,1>,<1,1>,<1,2>,<2,0>
        int length = nums.size();
        //result1保存低位基数排序的结果
        vector<int> result1(length + 1, 0);
        //result2保存高位基数排序的结果
        vector<int> result2(length + 1, 0);
        //count用来统计一趟基数排序中各个数位出现的次数，由于nums里面数值范围是从1到26，所以count长度不能小于26。
        //且在第二次进入该函数时，nums数组里面放的是当前阶段各子串的排名，到最后有length个子串，即有length个排名值，所以count的长度也不能低于length
        vector<int> count(max(27, length), 0);

        //低位基数排序，低位数组 = [1,2,1,1,1,1,2,0]， 完成后result1 = [7,0,2,3,4,5,1,6]
        for(int i = 0; i < length; i++){
            int digit = (i+step)<length?nums[i+step]:0;
            count[digit]++;
        }
        for(int i = 1; i < count.size(); i++){
            count[i] += count[i-1];
        }
        for(int i = length-1; i >= 0; i--){
            int digit = (i+step)<length?nums[i+step]:0;
            result1[count[digit]-1] = i;
            count[digit]--;
        }

        //高位基数排序，高位数组 = [1,1,2,1,1,1,1,2]， 完成后result2 = [0,3,4,5,1,6,7,2]
        for (int i = 0; i < count.size(); ++i) {
            count[i] = 0;
        }
        for(int i = 0; i < length; i++){
            int digit = nums[i];
            count[digit]++;
        }
        for(int i = 1; i < count.size(); i++){
            count[i] += count[i-1];
        }
        for(int i = length-1; i >=0; i--){
            int digit = nums[result1[i]];
            result2[count[digit]-1] = result1[i];
            count[digit]--;
        }

        //result2前4个值为0,3,4,5，分别代表起始下标为0,3,4,5的4个<1,1>，这些只能占用一个排名号，即1
        //根据result2里面的基数排序结果，重新编排，使相等的元素只占用一个排名，结果保存到result1，完成后result1 = [1,2,4,1,1,1,2,3]
        result1[result2[0]] = 1;
        for(int i = 1; i < length; i++){
            int index1 = result2[i];
            int index2 = result2[i-1];
            if(nums[index1] == nums[index2] && ((index1+step)<length?nums[index1+step]:0) == ((index2+step)<length?nums[index2+step]:0)){
                result1[index1] = result1[index2];
            }else{
                result1[index1] = result1[index2]+1;
            }
        }
        //结果复制到nums里面，便于进行下一轮
        for (int i = 0; i < nums.size(); ++i) {
            nums[i] = result1[i];
        }
        return result1[result2[length-1]]==length;
    }

    vector<int> getHeight(vector<int> nums, vector<int> rank, vector<int> sa){
        int length = nums.size();
        vector<int> height(length, 0);
        //step表明前一趟比较的结果，可以使得这一趟比较跳过前面若干位
        int step = 0;
        for(int i = 0; i < length; i++){
            //若当前后缀是排名第1的，则无法计算height，跳过
            if(rank[i] == 1){
                step = 0;
                continue;
            }
            //index1和index2分别表示suffix(i)和它前一名的后缀的起始比较位置
            int index1 = i+step;
            int index2 = sa[rank[i]-2] - 1 + step;
            for(; index1 < length && index2 < length;){
                if(nums[index1] == nums[index2]){
                    index2++;
                    index1++;
                } else {
                    break;
                }
            }
            height[rank[i]-1] = index1 - i;
            step = max(0, index1 - i - 1);
        }
        return height;
    }
};

int main() {
    string s;
    cin >> s;
    cout << Solution().longestDupSubstring(s) << endl;
    return 0;
}