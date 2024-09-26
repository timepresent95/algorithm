import re
import sys

# sys.stdin = open("input.txt", "r")

document = input()

body = re.sub(r"<\/?main>", "", document)

tokens = list(
    filter(lambda x: x != "", re.split(r'<div title="(.*?)">(.*?)<\/div>', body))
)

answer = []


def extract(token):
    if token[0] != "<":
        return answer.append(f"title : {token.strip()}")

    paragraphs_list = list(re.split(r"<p>(.*?)<\/p>", token))
    for i in range(1, len(paragraphs_list), 2):
        paragraphs = paragraphs_list[i]
        content = re.sub(r"<\/?[a-zA-Z ]*?>", "", paragraphs).strip()
        answer.append(
            re.sub(r" {2,}", " ", content)
        )


for token in tokens:
    extract(token)

print("\n".join(answer).strip())
