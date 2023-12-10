function getMaxArea(n, ...heights) {
  const stack = [0];
  heights = [0, ...heights, 0];
  let answer = 0;
  for (let i = 1; i < heights.length; i++) {
    let topIndex = stack[stack.length - 1];
    while (heights[topIndex] > heights[i]) {
      minHeight = heights[stack.pop()];
      topIndex = stack[stack.length - 1];
      answer = Math.max(answer, (i - topIndex - 1) * minHeight);
    }
    stack.push(i);
  }
  return answer;
}

function solution(testCase) {
  const stack = [];
  for (let i = 0; i < testCase.length; i++) {
    if (testCase[i] === "0") {
      return;
    }
    console.log(getMaxArea(...testCase[i].split(" ").map((v) => parseInt(v))));
  }
}

// const filePath = "input.txt";
const filePath = "/dev/stdin";
const line = require("fs").readFileSync(filePath, "utf8");
let input = line.trim().split("\n");
solution(input);
