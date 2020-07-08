"https://leetcode.com/problems/sqrtx/"// (100% faster)
class Solution {
public:
    int mySqrt(int a) {
	double up=a,low=0;
	int ct=0;
	while(ct<300){
		double mid=(up+low)/2;
		double res=mid*mid; // calculate using binary expo here for nth root
		if(res<a){
			low=mid;
		}else up=mid;
		ct++;
	}
	return floor(low+0.00001);
    }
};

//for general case nth root: (from geekforgeeks : newton's algo) "
double nth(ll a,ll n){
	double ans=1;
	double up=a,low=0;
	int ct=0;
	while(ct<300){
		double mid=(up+low)/2;
		double m=mid,res=1.00;
		ll temp=n;
		while(temp){
			if(temp&1)res*=m;
			m=m*m;
			temp>>=1;
		}
		if(res<a){
			low=mid;
		}else up=mid;
		ct++;
	}
	return round((low+up)/2);
}