#!/usr/bin/python3
from flask import Flask, request, g
import sqlite3
import os
import binascii

app = Flask(__name__)
app.secret_key = os.urandom(32)

try:
    FLAG = open("./flag.txt", "r").read()
except:
    FLAG = "csean-ctf{fake_flag_for_local_testing}24"

DATABASE = "schema.db"
if os.path.exists(DATABASE) == False:
    db = sqlite3.connect(DATABASE)
    db.execute("CREATE TABLE users (name char(100), password char(100));")
    db.execute(f'INSERT INTO users (name, password) VALUES ("cseanctf", "cseanctf@2024"), ("csean-admin", "{FLAG.strip()}");')
    db.commit()
    db.close()


def get_db():
    db = getattr(g, '_database', None)
    if db is None:
        db = g._database = sqlite3.connect(DATABASE)
    db.row_factory = sqlite3.Row
    return db


def query_db(query, one=True):
    cur = get_db().execute(query)
    rv = cur.fetchall()
    cur.close()
    return (rv[0] if rv else None) if one else rv


@app.teardown_appcontext
def close_connection(exception):
    db = getattr(g, '_database', None)
    if db is not None:
        db.close()


def check(value):
    bklist = "admin"
    if bklist in value:
        return True


@app.route('/')
def index():
    return "just the index page fr"


@app.route('/login', methods=['POST'])
def login():
    username = request.form.get('username')
    password = request.form.get('password')

    if check(username) or check(password):
        return "hehe bro i told yah you ain't dumping me!"
        
    query = query_db(f'SELECT name from users where name="{username}" and password="{password}"')
    if query:
        username = query[0]
        if username == "csean-admin":
            return f"hello {username} you are the super admin" 
        return f"hello {username}"
    
    return "smh wrong credential"


app.run(host='0.0.0.0', port=1337)
