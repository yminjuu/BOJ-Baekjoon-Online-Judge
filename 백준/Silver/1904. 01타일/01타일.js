function solution(){
    let MOD = 15746;
    const input = require("fs").readFileSync(0).toString().trim();
    let n = Number(input);

    let arr = [];
    arr[1]= 1;
    arr[2]= 2;

    for (let i=3; i<=n; i++){
        arr[i] = (arr[i-2] + arr[i-1]) % MOD;
    }

    console.log(arr[n]);
}

solution();