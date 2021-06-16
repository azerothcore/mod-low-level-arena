-- Added help for commands
DELETE FROM `command` WHERE `name` IN ('lla queue solo', 'lla queue group');
INSERT INTO `command` (`name`, `security`, `help`) VALUES
('lla queue solo', 0, 'Syntax: .lla queue solo\r\n\r\nEnter in bg queue (arena skirmish) without group'),
('lla queue group', 0, 'Syntax: .lla queue group\r\n\r\nEnter in bg queue (arena skirmish) with group');
