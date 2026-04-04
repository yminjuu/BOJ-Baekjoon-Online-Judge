let candidate; // 해당 길이의 LIS 배열 중 최적의 배열 (마지막 값이 가장 작은)

function find(start, end, num){
    // 이진탐색으로 적합한 위치 찾기
    // 최대한 인덱스가 큰 곳

    while (start<end){
        let mid = Math.floor((start+end)/2);

        if (candidate[mid]<num){
            // 붙으면 손해 (이미 나보다 작음)
            start= mid+1;
        } else {
            // 붙으면 좋음
            end= mid;
        }
    }
    return start;
}

function solution(){
    const input = require("fs").readFileSync(0).toString().trim().split(/\s+/);

    let N= Number(input[0]);
    candidate = new Array(N+1).fill(0);

    let dp = new Array(N+1).fill(0); // 이 값이 저장된 LIS 배열의 인덱스
    let maxLth = 0;

    for (let i=1; i<=N; i++){
        let num= Number(input[i]);

        if (candidate[maxLth] < num){
            // 붙을 수 있음
            candidate[++maxLth]= num;
            dp[num]= maxLth;
        } else {
            let idx= find(0, maxLth, num);
            candidate[idx]= num;
            dp[num]= idx;
        }
    }

    console.log(maxLth);
}

solution();