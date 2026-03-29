function solution(){
    const input = require("fs").readFileSync(0).toString().trim().split(/\s+/);

    const N= Number(input[0]);

    let arr= []; let ptr=1;
    for (let i=0; i<N; i++){
        arr.push(Number(input[ptr++]));
    }

    let stck = [];
    let ans = [];
    for (let i=N-1; i>=0; i--){
        let n = arr[i];

        while (stck.length>0 && stck[stck.length-1] <= n){
            stck.pop();
        }

        if (stck.length==0) {
            ans.push(-1);
        } else {
            ans.push(stck[stck.length-1]);
        }

        stck.push(n);
    }
    
    ans.reverse();

    console.log(ans.join(" "));
}

solution();