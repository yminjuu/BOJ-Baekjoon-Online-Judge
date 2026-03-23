// 인접리스트
let arr;
let N,M,V;

// 큐를 직접 구현
class Queue {
    constructor() {
        this.storage= [];
        this.head=0; // 나가는 쪽 포인터
        this.tail=0; // 들어오는 쪽 포인터
    }
    push(item){
        this.storage[this.tail++]= item;
    }
    pop(){
        if (this.head===this.tail) return undefined; 
        return this.storage[this.head++];
    }
    size() {
        return this.tail - this.head;
    }
}

function bfs(n){
    let visited= Array.from({length: N+1}, ()=> 0);
    visited[n]= 1;

    let q = new Queue();

    q.push(n);
    visited[n]= 1;
    let ans = "";
    while (q.size()!=0){
        n = q.pop();
        ans = ans+n+" ";

        for (let i=1; i<= N; i++){
            if (!visited[i] && arr[n][i]){
                q.push(i);
                visited[i]= 1;
            }            
        }
    }
    console.log(ans);
}

let dfsRes = [];
let visited= Array.from({length: N+1}, ()=> 0);
function dfs(n){
    visited[n]= 1;
    dfsRes.push(n);

    for (let i=1; i<=N; i++){
        if (!visited[i] && arr[n][i]){
            visited[i]=1; 
            dfs(i);
        }
    }
}

function solution(){
    const input = require("fs").readFileSync(0).toString().trim().split(/\s+/);

    let idx= 0;
    const next = () => input[idx++];

    N= next(); M= next(); V= next();
    arr = Array.from({length: N+1}, ()=> Array(N+1).fill(0));
    // 첫번째 인자: 배열의 길이 정보만 가진 유사 정보 객체
    // 두번째 인자: 콜백함수, 배열값을 무엇으로 채울 것인가
    for (let i=0; i<M; i++){
        let a= next(); let b= next();
        arr[a][b]= 1;
        arr[b][a]=1;
    }

    dfs(V);
    console.log(dfsRes.join(" "));
    bfs(V);
}

solution();