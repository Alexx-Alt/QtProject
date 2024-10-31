CREATE TABLE IF NOT EXISTS `alexx2mh_test`.`courses` (
  `id` INT NOT NULL AUTO_INCREMENT,
  `title` VARCHAR(255) NOT NULL,
  `description` TEXT NULL DEFAULT NULL,
  `tegs_id` INT NULL DEFAULT NULL,
  PRIMARY KEY (`id`),
  INDEX `tegs_idx` (`tegs_id` ASC),
  CONSTRAINT `12`
    FOREIGN KEY (`tegs_id`)
    REFERENCES `alexx2mh_test`.`tegs_storage` (`id`)
    ON DELETE CASCADE
    ON UPDATE CASCADE);


-- ----------------------------------------------------------------------------
-- Table alexx2mh_test.forum_question
-- ----------------------------------------------------------------------------
CREATE TABLE IF NOT EXISTS `alexx2mh_test`.`forum_question` (
  `id` INT NOT NULL AUTO_INCREMENT,
  `author_id` INT NULL DEFAULT NULL,
  `text` TEXT NULL DEFAULT NULL,
  `Parent_id` INT NULL DEFAULT NULL,
  PRIMARY KEY (`id`));


-- ----------------------------------------------------------------------------
-- Table alexx2mh_test.lessons
-- ----------------------------------------------------------------------------
CREATE TABLE IF NOT EXISTS `alexx2mh_test`.`lessons` (
  `id` INT NOT NULL AUTO_INCREMENT,
  `course_id` INT NULL DEFAULT NULL,
  `title` VARCHAR(255) NOT NULL,
  `content` TEXT NULL DEFAULT NULL,
  PRIMARY KEY (`id`),
  INDEX `course_id` (`course_id` ASC) ,
  CONSTRAINT `lessons_ibfk_1`
    FOREIGN KEY (`course_id`)
    REFERENCES `alexx2mh_test`.`courses` (`id`)
    ON DELETE CASCADE);


-- ----------------------------------------------------------------------------
-- Table alexx2mh_test.notifications
-- ----------------------------------------------------------------------------
CREATE TABLE IF NOT EXISTS `alexx2mh_test`.`notifications` (
  `id` INT NOT NULL AUTO_INCREMENT,
  `user_id` INT NULL DEFAULT NULL,
  `title` VARCHAR(255) NOT NULL,
  `content` TEXT NULL DEFAULT NULL,
  PRIMARY KEY (`id`),
  INDEX `user_id` (`user_id` ASC) ,
  CONSTRAINT `notifications_ibfk_1`
    FOREIGN KEY (`user_id`)
    REFERENCES `alexx2mh_test`.`users` (`id`)
    ON DELETE CASCADE);

-- ----------------------------------------------------------------------------
-- Table alexx2mh_test.recommendations
-- ----------------------------------------------------------------------------
CREATE TABLE IF NOT EXISTS `alexx2mh_test`.`recommendations` (
  `id` INT NOT NULL AUTO_INCREMENT,
  `user_id` INT NULL DEFAULT NULL,
  `course_id` INT NULL DEFAULT NULL,
  `lesson_id` INT NULL DEFAULT NULL,
  PRIMARY KEY (`id`),
  INDEX `user_id` (`user_id` ASC) ,
  INDEX `course_id` (`course_id` ASC) ,
  INDEX `lesson_id` (`lesson_id` ASC) ,
  CONSTRAINT `recommendations_ibfk_1`
    FOREIGN KEY (`user_id`)
    REFERENCES `alexx2mh_test`.`users` (`id`)
    ON DELETE CASCADE,
  CONSTRAINT `recommendations_ibfk_2`
    FOREIGN KEY (`course_id`)
    REFERENCES `alexx2mh_test`.`courses` (`id`)
    ON DELETE CASCADE,
  CONSTRAINT `recommendations_ibfk_3`
    FOREIGN KEY (`lesson_id`)
    REFERENCES `alexx2mh_test`.`lessons` (`id`)
    ON DELETE CASCADE);

-- ----------------------------------------------------------------------------
-- Table alexx2mh_test.student_teacher
-- ----------------------------------------------------------------------------
CREATE TABLE IF NOT EXISTS `alexx2mh_test`.`student_teacher` (
  `id` INT NOT NULL AUTO_INCREMENT,
  `teacher_id` INT NULL DEFAULT NULL,
  `student_id` INT NULL DEFAULT NULL,
  PRIMARY KEY (`id`),
  INDEX `teacher_id` (`teacher_id` ASC) ,
  INDEX `student_id` (`student_id` ASC) ,
  CONSTRAINT `student_teacher_ibfk_1`
    FOREIGN KEY (`teacher_id`)
    REFERENCES `alexx2mh_test`.`users` (`id`)
    ON DELETE CASCADE,
  CONSTRAINT `student_teacher_ibfk_2`
    FOREIGN KEY (`student_id`)
    REFERENCES `alexx2mh_test`.`users` (`id`)
    ON DELETE CASCADE);

-- ----------------------------------------------------------------------------
-- Table alexx2mh_test.tasks
-- ----------------------------------------------------------------------------
CREATE TABLE IF NOT EXISTS `alexx2mh_test`.`tasks` (
  `id` INT NOT NULL AUTO_INCREMENT,
  `user_id` INT NULL DEFAULT NULL,
  `task` TEXT NOT NULL,
  `deadline` DATETIME NULL DEFAULT NULL,
  PRIMARY KEY (`id`),
  INDEX `user_id` (`user_id` ASC) ,
  CONSTRAINT `tasks_ibfk_1`
    FOREIGN KEY (`user_id`)
    REFERENCES `alexx2mh_test`.`users` (`id`)
    ON DELETE CASCADE);

-- ----------------------------------------------------------------------------
-- Table alexx2mh_test.tegs_storage
-- ----------------------------------------------------------------------------
CREATE TABLE IF NOT EXISTS `alexx2mh_test`.`tegs_storage` (
  `id` INT NOT NULL AUTO_INCREMENT,
  `title` TEXT NULL DEFAULT NULL,
  PRIMARY KEY (`id`));

-- ----------------------------------------------------------------------------
-- Table alexx2mh_test.test_answers
-- ----------------------------------------------------------------------------
CREATE TABLE IF NOT EXISTS `alexx2mh_test`.`test_answers` (
  `id` INT NOT NULL AUTO_INCREMENT,
  `user_id` INT NULL DEFAULT NULL,
  `test_id` INT NULL DEFAULT NULL,
  `score` INT NULL DEFAULT NULL,
  `completed_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`),
  INDEX `1_idx` (`test_id` ASC) ,
  INDEX `2_idx` (`user_id` ASC) ,
  CONSTRAINT `1`
    FOREIGN KEY (`test_id`)
    REFERENCES `alexx2mh_test`.`tests` (`id`)
    ON DELETE RESTRICT
    ON UPDATE RESTRICT,
  CONSTRAINT `2`
    FOREIGN KEY (`user_id`)
    REFERENCES `alexx2mh_test`.`users` (`id`)
    ON DELETE RESTRICT
    ON UPDATE RESTRICT);

-- ----------------------------------------------------------------------------
-- Table alexx2mh_test.test_questions
-- ----------------------------------------------------------------------------
CREATE TABLE IF NOT EXISTS `alexx2mh_test`.`test_questions` (
  `id` INT NOT NULL AUTO_INCREMENT,
  `test_id` INT NULL DEFAULT NULL,
  `question` TEXT NOT NULL,
  `correct_answer` TEXT NULL DEFAULT NULL,
  PRIMARY KEY (`id`),
  INDEX `test_id` (`test_id` ASC) ,
  CONSTRAINT `test_questions_ibfk_1`
    FOREIGN KEY (`test_id`)
    REFERENCES `alexx2mh_test`.`tests` (`id`)
    ON DELETE CASCADE);

-- ----------------------------------------------------------------------------
-- Table alexx2mh_test.test_results
-- ----------------------------------------------------------------------------
CREATE TABLE IF NOT EXISTS `alexx2mh_test`.`test_results` (
  `id` INT NOT NULL AUTO_INCREMENT,
  `user_id` INT NULL DEFAULT NULL,
  `test_count` INT NULL DEFAULT NULL,
  PRIMARY KEY (`id`),
  INDEX `user_id` (`user_id` ASC) ,
  CONSTRAINT `test_results_ibfk_1`
    FOREIGN KEY (`user_id`)
    REFERENCES `alexx2mh_test`.`users` (`id`)
    ON DELETE CASCADE);

-- ----------------------------------------------------------------------------
-- Table alexx2mh_test.tests
-- ----------------------------------------------------------------------------
CREATE TABLE IF NOT EXISTS `alexx2mh_test`.`tests` (
  `id` INT NOT NULL AUTO_INCREMENT,
  `lesson_id` INT NULL DEFAULT NULL,
  `title` VARCHAR(255) NOT NULL,
  `tegs_id` INT NULL DEFAULT NULL,
  PRIMARY KEY (`id`),
  INDEX `lesson_id` (`lesson_id` ASC) ,
  INDEX `test_tegs_idx` (`tegs_id` ASC) ,
  CONSTRAINT `test_tegs`
    FOREIGN KEY (`tegs_id`)
    REFERENCES `alexx2mh_test`.`tegs_storage` (`id`)
    ON DELETE RESTRICT
    ON UPDATE RESTRICT,
  CONSTRAINT `tests_ibfk_1`
    FOREIGN KEY (`lesson_id`)
    REFERENCES `alexx2mh_test`.`lessons` (`id`)
    ON DELETE CASCADE);

-- ----------------------------------------------------------------------------
-- Table alexx2mh_test.user_progress
-- ----------------------------------------------------------------------------
CREATE TABLE IF NOT EXISTS `alexx2mh_test`.`user_progress` (
  `id` INT NOT NULL AUTO_INCREMENT,
  `user_id` INT NULL DEFAULT NULL,
  `lesson_id` INT NULL DEFAULT NULL,
  `completed` TINYINT(1) NULL DEFAULT '0',
  `course_id` INT NULL DEFAULT NULL,
  `completed_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`),
  INDEX `user_id` (`user_id` ASC) ,
  INDEX `lesson_id` (`lesson_id` ASC) ,
  INDEX `user_progress_ibfk_3_idx` (`course_id` ASC) ,
  CONSTRAINT `user_progress_ibfk_1`
    FOREIGN KEY (`user_id`)
    REFERENCES `alexx2mh_test`.`users` (`id`)
    ON DELETE CASCADE,
  CONSTRAINT `user_progress_ibfk_2`
    FOREIGN KEY (`lesson_id`)
    REFERENCES `alexx2mh_test`.`lessons` (`id`)
    ON DELETE CASCADE,
  CONSTRAINT `user_progress_ibfk_3`
    FOREIGN KEY (`course_id`)
    REFERENCES `alexx2mh_test`.`courses` (`id`)
    ON DELETE RESTRICT
    ON UPDATE RESTRICT);


-- ----------------------------------------------------------------------------
-- Table alexx2mh_test.user_tegs
-- ----------------------------------------------------------------------------
CREATE TABLE IF NOT EXISTS `alexx2mh_test`.`user_tegs` (
  `id` INT NOT NULL AUTO_INCREMENT,
  `user_id` INT NULL DEFAULT NULL,
  `tegs_id` INT NULL DEFAULT NULL,
  PRIMARY KEY (`id`),
  INDEX `tegs_idx` (`tegs_id` ASC) ,
  CONSTRAINT `tegs`
    FOREIGN KEY (`tegs_id`)
    REFERENCES `alexx2mh_test`.`tegs_storage` (`id`)
    ON DELETE RESTRICT
    ON UPDATE RESTRICT);

-- ----------------------------------------------------------------------------
-- Table alexx2mh_test.users
-- ----------------------------------------------------------------------------
CREATE TABLE IF NOT EXISTS `alexx2mh_test`.`users` (
  `id` INT NOT NULL AUTO_INCREMENT,
  `username` VARCHAR(255) NOT NULL,
  `role` ENUM('student', 'teacher') NOT NULL,
  `level` INT NULL DEFAULT '1',
  `experience_points` INT NULL DEFAULT '0',
  `password` VARCHAR(255) NOT NULL,
  `email` VARCHAR(100) NULL DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE INDEX `email` (`email` ASC) );

