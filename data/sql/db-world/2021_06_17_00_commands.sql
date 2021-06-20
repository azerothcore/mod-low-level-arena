-- Added help for commands
DELETE FROM `command` WHERE `name` IN ('lla queue');
INSERT INTO `command` (`name`, `security`, `help`) VALUES
('lla queue', 0, 'Syntax: .lla queue\r\n\r\Queue Arena skirmish');
