/*
 * @Descripttion: 
 * @Author: KB
 * @Date: 2023-02-23 09:50:56
 * @LastEditors: KB
 * @LastEditTime: 2023-03-03 15:30:04
 */
/*
 * @lc app=leetcode.cn id=6 lang=c
 *
 * [6] Z 字形变换
 */

// @lc code=start
// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>
// char * convert(char * s, int numRows){
//     int len=strlen(s);
//     if(len==1){
//         return s;
//     }
//    // printf("%d\n",len);
//     char res[numRows][len];
//     int resindex[numRows];
//     for(int i=0;i<numRows;i++){
//         resindex[i]=0;
//     }
//     for(int i=0;i<numRows;i++){
//         for(int j=0;j<len;j++){
//             res[i][j]='*';
//         }
//     }
//     int groupNum=2*numRows-2;
//     int flag=-1;
//     int index=0;
//     for(int i=0;i<len;i++){
//         if(i%groupNum==numRows-1||i%groupNum==0){
//             flag=-flag;
//         }
        
//         res[index][resindex[index]]=s[i];
//         resindex[index]++;
//         index+=flag;
//     }
//     char *result=(char*)malloc((len+1)*sizeof(char));
//     index=0;
//     for(int i=0;i<numRows;i++){
//         for(int j=0;j<len&&res[i][j]!='*';j++){
//             result[index++]=res[i][j];
//         }
//     }
//     result[len]='\0'; 
//    // printf("%s\n",result);
//     return result;
// }

char * convert(char *s,int numRows){
    int l=strlen(s);
    int r=numRows;
    if(l==1||r>=l){
        return s;
    }
    int pos=0;
    int cycle=2*r-2;
    char *res=(char*)malloc((l+1)*sizeof(char));
    for(int i=0;i<r;i++){
        for(int j=0;j+i<l;j+=cycle){
            res[pos++]=s[j+i];
            if(0<i&&i<r-1&&j+cycle-i<l){
                res[pos++]=s[j+cycle-i];
            }
        }
    }
    res[pos]='\0';
    return res;
}
// @lc code=end

