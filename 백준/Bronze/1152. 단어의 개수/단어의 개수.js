function solution(){
    const input = require("fs").readFileSync(0).toString().trim().split(/\s+/).filter(v => v!=="");

    let idx =0;
    const next = () => input[idx++]; // 다음 input을 내뱉는 함수

    console.log(input.length);
}

solution();