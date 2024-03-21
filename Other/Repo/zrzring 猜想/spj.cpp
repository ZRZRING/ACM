/***
keep hungry and calm PushyTao!
Data: 2023.3.2
QQ: 169961689
***/
#include<bits/stdc++.h>
using namespace std;

#define AC 0
#define WA 1

void jscanf(FILE *&fin, const char *format, ...) {
	va_list args;
	va_start(args, format);   /* 初始化变长参数列表 */
	int ret = vfscanf(fin, format, args);
	va_end(args);         /* 结束使用变长参数列表 */
	if (ret == EOF) {
		printf("When reading data, the program crashes because EOF is encountered in advance.\n");
		exit(WA);
	}
}

bool is_whitespace(const char c) {
	return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

//检查用户是否存在多余输出
int read_until_eof(FILE *&fp) {
	char ch = fgetc(fp);
	while (ch != EOF && is_whitespace(ch)) {
		ch = fgetc(fp);
	}
	if (ch != EOF) {
		printf("There is redundant content in user output\n");
		return WA;
	}
	return AC;
}

int judge(FILE *&std_in, FILE *&std_out, FILE *&user_out);

int main(int argc, char *args[]) {
	if (argc <= 1) {
		printf("Please enter the path of input file, output file, and contestant output file in turn:\n");
		for (int i = 1; i <= 3; i++) {
			args[i] = new char[100];
			scanf("%s", args[i]);
		}
	}
	FILE *in = fopen(args[1], "r");   //测试输入
	FILE *out = fopen(args[2], "r");  //测试输出
	FILE *user = fopen(args[3], "r"); //用户输出
	if (in == NULL)
		printf("No such a file with path %s\n", args[1]);
	if (out == NULL)
		printf("No such a file with path %s\n", args[2]);
	if (user == NULL)
		printf("No such a file with path %s\n", args[3]);

	int result = AC;
	if (!in || !out ||!user)
		result = WA;

	if (judge(in, out, user) != AC || read_until_eof(user) != AC)
		result = WA;

	fclose(in);
	fclose(out);
	fclose(user);
	return result;
}
/*************************** 以上内容请勿修改！！！ ***********************/
const int N = 1e6+10;
int a[N];
map<int, int>mp;
/*************************** 请在下面的jduge函数体内编写特判逻辑！ ***********************/
int judge(FILE *&fin, FILE *&std_out, FILE *&fout) {
    int n;
	fscanf(fout, "%d", &n);
    if(n > 1001){
        return WA;
    }
    mp.clear();
	memset(a, 0x3f, sizeof(a));
    for(int i = 1;i <= n;i++){
        fscanf(fout,"%d",&a[i]);
        if(i != 1){
            int ans = a[i - 1] - a[i];
            mp[ans]++;
            if(mp[ans] > 2){
                return WA;
            }
        }
    }
    int x;
    fscanf(fin,"%d",&x);
    if(a[1] != x || a[n] != 1){
        return WA;
    }
    for(int i = 2;i <= n;i++){
        int ans = a[i - 1] - a[i];
        if(ans == 0){
            return WA;
        }
        if(a[i - 1] % ans != 0){
            return WA;
        }
    }
    return AC;
}
