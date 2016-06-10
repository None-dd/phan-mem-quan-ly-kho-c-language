-- phpMyAdmin SQL Dump
-- version 4.4.14
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1
-- Generation Time: Jan 03, 2016 at 08:56 PM
-- Server version: 5.6.26
-- PHP Version: 5.6.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `management_store`
--

-- --------------------------------------------------------

--
-- Table structure for table `product`
--

CREATE TABLE IF NOT EXISTS `product` (
  `tensanpham` varchar(20) CHARACTER SET utf8 NOT NULL,
  `masanpham` varchar(10) NOT NULL,
  `giatien` int(10) DEFAULT '0',
  `soluong` int(10) unsigned NOT NULL,
  `mota` text CHARACTER SET utf8 NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `product`
--

INSERT INTO `product` (`tensanpham`, `masanpham`, `giatien`, `soluong`, `mota`) VALUES
('san pham 1', 'sp1', 0, 10, 'san pham cua cong ty X'),
('san pham 2', 'sp2', 100000, 10, 'san pham cua cong ty X'),
('san pham 3', 'sp3', 100000, 10, 'san pham cua cong ty X'),
('san pham 4', 'sp4', 100000, 10, 'san pham cua cong ty X'),
('san pham 5', 'sp5', 100000, 10, 'san pham cua cong ty X'),
('san pham 6', 'sp6', 100000, 10, 'san pham cua cong ty X'),
('san pham 7 ', 'sp7', 100000, 10, 'san pham cua cong ty X'),
('san pham 8', 'sp8', 100000, 10, 'san pham cua cong ty X'),
('san pham 9', 'sp9', 100000, 10, 'san pham cua cong ty X'),
('san pham moi', 'sp_new', 10000, 16, 'san pham moi cua cong ty X'),
('san pham x', 'sp_X', 100000, 10, 'san pham cua cong ty X');

-- --------------------------------------------------------

--
-- Table structure for table `users`
--

CREATE TABLE IF NOT EXISTS `users` (
  `username` varchar(20) CHARACTER SET utf8 NOT NULL,
  `password` varchar(20) CHARACTER SET utf8 NOT NULL,
  `privilege` int(1) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `users`
--

INSERT INTO `users` (`username`, `password`, `privilege`) VALUES
('admin', '123456', 1),
('xx', '1234', 0);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `product`
--
ALTER TABLE `product`
  ADD PRIMARY KEY (`masanpham`);

--
-- Indexes for table `users`
--
ALTER TABLE `users`
  ADD PRIMARY KEY (`username`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
