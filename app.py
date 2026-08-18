# app.py — Flask Student Grade Viewer
# Sanjay Ghodawat University | DVOps & MLOps Lab | Experiment E3

from flask import Flask, render_template

app = Flask(__name__)

# Sample student data
students = [
    {"name": "Aditya Patil", "roll": "A001", "marks": 88, "grade": "A"},
    {"name": "Priya Kulkarni", "roll": "A002", "marks": 75, "grade": "B"},
    {"name": "Rahul Sharma", "roll": "A003", "marks": 92, "grade": "A+"},
    {"name": "Sneha Desai", "roll": "A004", "marks": 61, "grade": "C"},
    {"name": "Vikram More", "roll": "A005", "marks": 79, "grade": "B+"},
]


@app.route('/')
def index():
    avg = sum(s['marks'] for s in students) / len(students)
    return render_template(
        'index.html',
        students=students,
        avg=round(avg, 2)
    )


@app.route('/health')
def health():
    return {
        "status": "ok",
        "server": "AWS EC2",
        "experiment": "E3"
    }, 200


if __name__ == '__main__':
    # 0.0.0.0 makes the server accessible outside EC2
    app.run(host='0.0.0.0', port=5000, debug=False)