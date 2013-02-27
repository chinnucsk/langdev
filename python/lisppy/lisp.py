#!/usr/bin/env python

import re
import sys

errfile = "<lisp>"

def read(sexpr):
    grammar = r"(\()|(\))|([^()\s]+)|(\s+)"

    def sequenceBuilder(match):
        leftbracket, rightbracket, atom, whitespace = match.groups()
        if(leftbracket): return '['
        elif(rightbracket): return ']'
        elif(atom): return '"' + atom + '"'
        elif(whitespace): return ','
    return eval(re.sub(grammar, sequenceBuilder, sexpr), None, None)

def label(rest):
    if(len(rest) == 2): # a variable
        globalScope.append((comp(rest[0]), comp(rest[1])))
    else: # a function
        globalScope.append((comp(rest[0]), "lambda " + comp(rest[1]).strip("[]") +": " + comp(rest[2])))
    return "None"

specialForms = {
    "eq": lambda rest: "("+comp(rest[0])+" == "+comp(rest[1])+")",
    "quote": lambda rest: "[" + ", ".join(map(lambda x: comp(x), rest)) + "]",
    "car": lambda rest: "(" + comp(rest[0]) + ")[0]",
    "cdr": lambda rest: "(" + comp(rest[0]) + ")[1:]",
    "cons": lambda rest: "[" + comp(rest[0])+"] + " + comp(rest[1]),
    "cond": lambda rest: "("+comp(rest[1])+" if "+comp(rest[0])+" else "+comp(rest[2])+")",
    "label": label,
    "+": lambda rest: comp(rest[0])+" + "+comp(rest[1]),
    "-": lambda rest: comp(rest[0])+" - "+comp(rest[1]),
    "*": lambda rest: "("+comp(rest[0])+") * ("+comp(rest[1])+")",
    "/": lambda rest: "("+comp(rest[0])+") / ("+comp(rest[1])+")"
}

globalScope = []
def comp(tree):
    if(type(tree) == list):
        if(tree[0] in specialForms):
            return specialForms.get(tree[0])(tree[1:])
        else:
            args = map(lambda x: comp(x), tree[1:])
            return tree[0] + "(" + ",".join(args) + ")"
    else:
        return tree

def transcribe(sexpr):
    tree = read(sexpr)
    if(type(tree) == tuple):
        transcripts = []
        for node in tree:
            transcripts.append(comp(node))
        transcript = "\n".join(transcripts)
    else:
        transcript = comp(tree)

    initCode = []
    for expr in globalScope:
        initCode.append(str(expr[0]) + " = " + str(expr[1]) + "\n")
    return "".join(initCode) + transcript

def lisp(sexpr):
    transcript = transcribe(sexpr)
    print transcript

def repl():
    while(True):
        print "lisp> ",
        sys.stdout.flush()
        line = sys.stdin.readline().lstrip(">").strip()
        try:
            lisp(line)
        except:
            print "???"

if __name__ == "__main__":
    if(len(sys.argv) == 2):
        f = open(sys.argv[1])
        lisp(f.read())
        f.close()

    else:
        print "A Lisp to Python compiler."
        print
        repl()
