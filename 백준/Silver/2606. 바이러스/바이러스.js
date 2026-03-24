let N, E;
let visited;
let arr= [];

function bfs(n){
    for (let i=0; i<arr[n].length; i++){
        let next = arr[n][i];
        if (!visited[next]) {
            visited[next]= 1;
            bfs(next);
        }
    }
}

function solution(){
    const input = require("fs").readFileSync(0).toString().trim().split(/\s/);
    N = Number(input[0]);
    E = Number(input[1]);
    visited= new Array(N+1).fill(false);

    // 인접리스트 
    arr = Array.from({length: N+1}, ()=> []);
    let idx= 2;
    for (let i=0; i<E; i++){
        let a= input[idx++];
        let b= input[idx++];
        arr[a].push(b);
        arr[b].push(a);
    }

    visited[1]= true;
    bfs(1);

    let ans=0;
    for (let i=2; i<=N; i++){
        if (visited[i]) ans++;
    }
    console.log(ans);
}

solution();