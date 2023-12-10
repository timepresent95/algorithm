function greedy(caseA, caseB) {
  if (caseB === null) {
    return caseA;
  }
  if (caseA.garbage === caseB.garbage) {
    return caseA.closeIndex < caseB.closeIndex ? caseA : caseB;
  }
  return caseA.garbage < caseB.garbage ? caseA : caseB;
}

function getMinCount(input) {
  const n = input.length;
  const memo = Array.from({ length: n }, () => new Array(n));
  // [openCase, closeCase]
  memo[0][0] = [{ closeIndex: null, garbage: 1 }, null];
  const pairOpen = { ")": "(", "}": "{", "]": "[" };
  for (let i = 1; i < n; i++) {
    memo[i][i] = [{ closeIndex: null, garbage: 1 }, null];
    for (let j = i - 1; j >= 0; j--) {
      let closeCase = null;
      if (memo[i][j + 1][1] !== null) {
        const prev = memo[i][j + 1][1];
        closeCase = {
          closeIndex: prev.closeIndex,
          garbage:
            memo[i][prev.closeIndex][1].garbage +
            greedy(...memo[prev.closeIndex - 1][j]).garbage,
        };
      }
      const greedyOpenPrev = greedy(memo[i - 1][j][0], memo[i - 1][j][1]);
      const openCase = {
        closeIndex: greedyOpenPrev.closeIndex,
        garbage: greedyOpenPrev.garbage + 1,
      };
      if (pairOpen[input[i]] === input[j]) {
        closeCase = greedy(
          {
            closeIndex: j,
            garbage: memo[i][j + 1][0].garbage - 1,
          },
          closeCase
        );
      }
      memo[i][j] = [openCase, closeCase];
    }
  }
  // for (let i = 0; i < n; i++) {
  //   console.log(i);
  //   for (let j = 0; j <= i; j++) {
  //     console.log(j, memo[i][j][0], memo[i][j][1]);
  //   }
  // }
  return greedy(memo[n - 1][0][0], memo[n - 1][0][1]).garbage;
}

function solution(testCase, ...input) {
  testCase = parseInt(testCase);
  for (let i = 0; i < testCase; i++) {
    console.log(getMinCount(input[i]));
  }
}
// const filePath = "input.txt";
const filePath = "/dev/stdin";
const line = require("fs").readFileSync(filePath, "utf8");
let input = line.split("\n").map((v) => v.trim());
solution(...input);
