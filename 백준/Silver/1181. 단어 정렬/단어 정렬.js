function solution(){
    const input = require("fs").readFileSync(0).toString().trim().split(/\n/);
    const N = Number(input[0]);
    let arr = [];

    for (let i=1; i<=N; i++){
        arr.push(input[i]);
    }

    let uniqArr= [];
    uniqArr= [...new Set(arr)];

    uniqArr.sort((a,b)=> {
        if (a.length!== b.length) return a.length-b.length; // 짧을수록

        if (a<b) return -1; // 사전적으로 앞에 있음
        if (a>b) return 1;
        return 0;
    });

    let ans = "";
    for (let i=0; i<uniqArr.length; i++){
        ans+= uniqArr[i] + "\n";
    }
    console.log(ans);
}

solution();