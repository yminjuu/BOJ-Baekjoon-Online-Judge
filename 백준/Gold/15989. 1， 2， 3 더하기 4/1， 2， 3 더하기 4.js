function solution(){
    const input = require("fs").readFileSync(0).toString().trim().split(/\n/);
    const T = Number(input[0]);

    let arr =[];
    for (let i=1; i<=T; i++){
        let n = Number(input[i]);
        arr.push(n);
    }
    let biggest= Math.max(...arr);

    let dp = new Array(biggest+1).fill(0);
    dp[0]= 1; // 2, 3일 때의 초깃값이 옳게 들어가도록
    for (let i=1; i<=3; i++){
        for (let j=i; j<= biggest; j++){
            dp[j] += dp[j-i];
        }
    }    

    let ans = [];
    for (let i=0; i<arr.length; i++){
        ans.push(dp[arr[i]]);
    }
    console.log(ans.join("\n"));
}

solution();