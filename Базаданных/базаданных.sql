CREATE DATABASE learningv1;

USE learningv1;
CREATE TABLE users (
    id INT PRIMARY KEY AUTO_INCREMENT,
    username VARCHAR(50) UNIQUE,
    password_hash VARCHAR(255),
    email VARCHAR(100) UNIQUE,
    role ENUM('student', 'teacher', 'admin'),
    created_at DATETIME DEFAULT NOW(),
    updated_at DATETIME DEFAULT NOW() ON UPDATE NOW()
);

CREATE TABLE courses (
    id INT PRIMARY KEY AUTO_INCREMENT,
    title VARCHAR(100),
    description TEXT,
    created_at DATETIME DEFAULT NOW(),
    updated_at DATETIME DEFAULT NOW() ON UPDATE NOW()
);

CREATE TABLE lessons (
    id INT PRIMARY KEY AUTO_INCREMENT,
    course_id INT,
    title VARCHAR(100),
    content TEXT,
    position INT,
    created_at DATETIME DEFAULT NOW(),
    updated_at DATETIME DEFAULT NOW() ON UPDATE NOW(),
    FOREIGN KEY (course_id) REFERENCES courses(id)
);

CREATE TABLE user_progress (
    id INT PRIMARY KEY AUTO_INCREMENT,
    user_id INT,
    course_id INT,
    lesson_id INT,
    is_completed BOOLEAN,
    completion_date DATETIME,
    FOREIGN KEY (user_id) REFERENCES users(id),
    FOREIGN KEY (course_id) REFERENCES courses(id),
    FOREIGN KEY (lesson_id) REFERENCES lessons(id)
);

CREATE TABLE tests (
    id INT PRIMARY KEY AUTO_INCREMENT,
    course_id INT,
    lesson_id INT,
    title VARCHAR(100),
    description TEXT,
    created_at DATETIME DEFAULT NOW(),
    FOREIGN KEY (course_id) REFERENCES courses(id),
    FOREIGN KEY (lesson_id) REFERENCES lessons(id)
);

CREATE TABLE test_questions (
    id INT PRIMARY KEY AUTO_INCREMENT,
    test_id INT,
    question_text TEXT,
    correct_answer TEXT,
    FOREIGN KEY (test_id) REFERENCES tests(id)
);

CREATE TABLE test_answers (
    id INT PRIMARY KEY AUTO_INCREMENT,
    question_id INT,
    answer_text TEXT,
    is_correct BOOLEAN,
    FOREIGN KEY (question_id) REFERENCES test_questions(id)
);

CREATE TABLE test_results (
    id INT PRIMARY KEY AUTO_INCREMENT,
    user_id INT,
    test_id INT,
    score DECIMAL(5, 2),
    taken_at DATETIME DEFAULT NOW(),
    FOREIGN KEY (user_id) REFERENCES users(id),
    FOREIGN KEY (test_id) REFERENCES tests(id)
);

CREATE TABLE recommendations (
    id INT PRIMARY KEY AUTO_INCREMENT,
    user_id INT,
    course_id INT,
    lesson_id INT,
    recommendation_text TEXT,
    recommended_date DATETIME DEFAULT NOW(),
    FOREIGN KEY (user_id) REFERENCES users(id),
    FOREIGN KEY (course_id) REFERENCES courses(id),
    FOREIGN KEY (lesson_id) REFERENCES lessons(id)
);

CREATE TABLE tasks (
    id INT PRIMARY KEY AUTO_INCREMENT,
    user_id INT,
    task_text TEXT,
    due_date DATETIME,
    is_completed BOOLEAN,
    FOREIGN KEY (user_id) REFERENCES users(id)
);

CREATE TABLE notifications (
    id INT PRIMARY KEY AUTO_INCREMENT,
    title VARCHAR(100),
    content TEXT,
    created_at DATETIME DEFAULT NOW()
);
