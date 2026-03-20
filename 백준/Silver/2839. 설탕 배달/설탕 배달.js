function solution(){
     const input = require("fs").readFileSync(0).toString();
    const N= Number(input);
    
    let five = Math.floor(N/5); // 최대 5 개수
    let ans = -1;
    
    for (; five>=0; five--){
        let R = N - 5*five;
        if (R%3==0) {
            ans = five + R/3;
            break;
        }
    }
    
    console.log(ans);   
}

solution();