class MinHeap {
    constructor(){
        this.heap= [];
    }

    push(value){
        this.heap.push(value);
        this.bubbleUp();
    }

    pop(){
        if (this.heap.length===0) return null;
        if (this.heap.length===1) return this.heap.pop();
        
        let min = this.heap[0];
        this.heap[0]= this.heap.pop();
        this.bubbleDown();
        return min;
    }

    // 새로 삽입된 원소를 알맞은 위치에
    bubbleUp(){
        let index= this.heap.length-1;

        while (index>0){
            let parent = Math.floor((index-1)/2);
             if (this.heap[index] >= this.heap[parent]) break;

            [this.heap[index], this.heap[parent]] = [this.heap[parent], this.heap[index]];
            index= parent;
        }
    }

    // pop 후 마지막 원소가 맨 위로 간 상태, 다시 정상화
    bubbleDown(){
        let index=0;
        const length = this.heap.length; // left, right가 모두 유효할 거란 보장은 없다

        while (true){
            let left= index*2+1;
            let right = index*2+2;
            let smallest = index;  // 비교대상

            if (left<=length && this.heap[left]<this.heap[smallest]) smallest=left;
            if (right<=length && this.heap[right]<this.heap[smallest]) smallest= right;

            if (smallest==index) break;
            [this.heap[smallest], this.heap[index]] = [this.heap[index], this.heap[smallest]];
            index= smallest;
        }
    }
}

function solution(){
    let pq = new MinHeap();

    let input = require("fs").readFileSync(0).toString().trim().split(/\s+/).map(Number);
    let N= input[0];

    let inputIdx=1;

    let ans = [];
    for (let i=0; i<N; i++){
        let x = input[inputIdx++];
        if (x>0){
            pq.push(x);
        } else {
            let min = pq.pop();
            if (!min) ans.push(0);
            else ans.push(min);
        }
    }

    console.log(ans.join('\n'));
}

solution();