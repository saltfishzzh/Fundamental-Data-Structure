//
//  main.c
//  bonus_3
//
//  Created by 张倬豪 on 2016/10/24.
//  Copyright © 2016年 Icarus. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 505

int cMax, n, problemBike, m,
    takeBackMin = 1 << 10,      //The minimum number of bikes that must be taken back
    sendBikeMin = 1 << 10,      //The minimum number of bikes that need to send from PBMC
    finalLength = 0;            //The final result's length of the path

int bikeNum[MAXN] = {0},        //The bike number of each station
    bikeMap[MAXN][MAXN] = {0},  //The map of all the bike, bikemap[s1][s2] means the road between s1, s2
    beenThere[MAXN] = {0},      //If beenThere[i]==0 means this station has not been reached
    roadmin[MAXN] = {0};        //The path of final result

void Find(int now) {
    static int length = 0, takeBack = 0, sendBike = 0, lengthMin = 1 << 10, stackIndex = 0;
    static int road[MAXN] = {0};
    int i, flag, sendBike_Last, takeBack_Last;
    if (length > lengthMin) return;   //If the current length is longer than min, return
    if (now == problemBike) {   //If the recursion is now at the problem bike
        flag = 0;
        
        /*If the current path satisfies these three conditions then renew data:
         1. If the length is shorter than min
         2. If the length is the same as min, check the send number of bike
         3. If the send number of bike is the same as min, check the number of taking back*/
        if (length < lengthMin || sendBike < sendBikeMin ||(sendBike == sendBikeMin && takeBack < takeBackMin)) flag = 1;
        
        /*If flag==1, which satisfies the former line conditions, 
         then the current path is better than the minimum path. So renew all the data*/
        if (flag) {
            lengthMin = length;
            sendBikeMin = sendBike;
            takeBackMin = takeBack;
            memcpy(roadmin, road, sizeof(road));
            finalLength = stackIndex;
        }
        return;
    }
    for (i = 0; i <= n; i++) {
        //If i has not been reached and there is a road between the current station and i
        if (beenThere[i] == 0 && bikeMap[now][i] > 0) {
            beenThere[i] = 1;
            length = length + bikeMap[now][i];
            sendBike_Last = sendBike;
            takeBack_Last = takeBack;   //Store the current number of send bike and number of taking back
            road[stackIndex++] = i;     //Add i into the path
            
            /*Calculate sendBike and tackBack to satisfy HALF-FULL*/
            if (bikeNum[i] + takeBack < cMax / 2){
                sendBike = sendBike + cMax / 2 - bikeNum[i] - takeBack;
                takeBack = 0;
            }
            else if (bikeNum[i] + takeBack == cMax / 2) takeBack = 0;
            else takeBack = bikeNum[i] + takeBack - cMax / 2;

            Find(i);                    //Recursion
            
            stackIndex--;
            sendBike = sendBike_Last;
            takeBack = takeBack_Last;
            length = length - bikeMap[now][i];
            beenThere[i] = 0;           //Get all the values back
        }
    }
}

void print(int finalLength) {
    int i;
    printf("%d 0", sendBikeMin);                               //The first station must be 0 (PBMC)
    for (i = 0; i < finalLength; i++) printf("->%d", roadmin[i]);
    printf(" %d", takeBackMin);
}

int main(int argc, const char * argv[]) {
    int i, station1, station2, time;
    
    /*Read all the data*/
    scanf("%d%d%d%d", &cMax, &n, &problemBike, &m);
    for (i = 1; i <= n; i++) scanf("%d", &bikeNum[i]);  //Read the bike numbers
    for (i = 0; i < m; i++) {
        scanf("%d%d%d", &station1, &station2, &time);   //Read the roads
        bikeMap[station1][station2] = bikeMap[station2][station1] = time;
        //Store the roads at both directions
    }
    
    /*Initialize and begin the process*/
    beenThere[0] = 1;
    Find(0);    //Start finding
    
    /*Print the result*/
    print(finalLength); //Res is the length of the road
    return 0;
}
