function solution(){
    let input = require("fs").readFileSync(0).toString().trim().split(/\s+/).map(Number);

    let arr= [];
    let N= input[0]; let goalCnt= input[1];

    let inputIdx= 2;
    for (let i=0; i<N; i++){
        let a= input[inputIdx++];
        let b= input[inputIdx++];
        if (a>=b) goalCnt--;
        else arr.push(b-a);
    }

    if (goalCnt<=0) {
        console.log(0);
        return 0;
    }

    arr.sort((a,b)=> a-b);
    console.log(arr[goalCnt-1]);
}

solution();