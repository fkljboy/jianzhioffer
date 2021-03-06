class Solution {
public:
    int cutRope(int length){
         if(length==1)
	    	return 0;
	    if(length==2)
	    	return 1;
	    if(length==3)
	    	return 2;
	    int max=0;//存储当前最大的f(n)
	    int array[length+1] ;//array[n] = f[n]
	    array[0]=0;
	    array[1]=1;
	    array[2]=2;
	    array[3]=3;
	    for(int i=4;i<=length;i++) {
	    	for(int f=1;f<=i/2;f++) {//绳子只需要剪前一半的就可以，剪i和剪n-i是一回事
	    		int pro = array[f]*array[i-f];
	    		if(pro>max)
	    			max=pro;
	    		array[i]=max;
	    	}
	    }
	    return array[length];

    }
};
/* 全篇唯一一个典型的动态规划题，大完结，观察发现前三个数都可以找到最大值
而第四个数的最大值是第三个数的最大值必定是前几个数中的最大值的乘积，所以
需要遍历一下 */