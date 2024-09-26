#!/usr/bin/env python3
from flask import Flask, request
import os

app = Flask(__name__)

@app.route('/' , methods=['GET'])
def index():
    c = request.args.get('c', '')
    if not c:
        return "hmm gimme something"

    if request.method == 'GET':
        ''
    else:
        os.system(c)
    return c

app.run(host='0.0.0.0', port=1337) 
