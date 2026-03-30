function solution(){
    const input = require("fs").readFileSync(0).toString().trim().split(/\n/);
    const T = Number(input[0]);

    let arr =[];
    for (let i=1; i<=T; i++){
        let n = Number(input[i]);
        arr.push(n);
    }
    let biggest= Math.max(...arr);

    //////// dp 사용 : 차곡차곡 쌓아나가기

    let dp = [];

    // (1) 1 사용
    for (let i=1; i<= biggest; i++){
        dp[i]= 1;
    }

    // (2) 2 사용
    for (let i=1; i<= biggest; i++){
        // 2가 최대로 들어갈 수 있는 횟수
        let n = Math.floor(i/2);
        dp[i] += n;
    }

    // (3) 3 사용
    dp[3]+=1;
    for (let i=4; i<= biggest; i++){
        dp[i] += dp[i-3];
    }

    let ans = [];
    for (let i=0; i<arr.length; i++){
        ans.push(dp[arr[i]]);
    }
    console.log(ans.join("\n"));
}

solution();