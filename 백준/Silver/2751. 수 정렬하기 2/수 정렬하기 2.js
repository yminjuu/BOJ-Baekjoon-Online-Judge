function solution(){
    const input = require("fs").readFileSync(0).toString().trim().split("\n");
    const N= input[0];

    let arr= [];
    let tmp=[];
    for (let i=1; i<=N; i++){
        const n= Number(input[i]);
        arr.push(n);
    }

    const sort = (start, end) => {
        if (start >= end) return;

        const mid = Math.floor((start+end)/2);
        sort(start, mid);
        sort(mid+1, end);
        merge(start, mid, end);
    }

    const merge = (start, mid, end) => {
        let p = start;
        let q = mid+1;
        let idx=  start;

        while (p<=mid && q<=end) {
            if (arr[p]> arr[q]) tmp[idx++]=arr[q++];
            else tmp[idx++]= arr[p++];
        }

        while (p<=mid) tmp[idx++]= arr[p++];
        while (q<=end) tmp[idx++]= arr[q++];

        for (let i=start; i<=end; i++){
            arr[i]= tmp[i];
        }
    }

    let s=0; let e=arr.length-1;
    sort(s, e);
    console.log(arr.join("\n"));
}

solution();