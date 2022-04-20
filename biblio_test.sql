-- MySQL dump 10.13  Distrib 8.0.28, for Linux (x86_64)
--
-- Host: localhost    Database: bibliotheque
-- ------------------------------------------------------
-- Server version	8.0.28-0ubuntu0.20.04.3

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `Adherents`
--

DROP TABLE IF EXISTS `Adherents`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Adherents` (
  `num_Adh` varchar(30) NOT NULL,
  `nom` varchar(30) NOT NULL,
  `prenoms` varchar(100) NOT NULL,
  `age` int NOT NULL,
  `contact` varchar(10) DEFAULT NULL,
  `residence` varchar(30) DEFAULT NULL,
  `sexe` tinyint(1) NOT NULL DEFAULT '0',
  PRIMARY KEY (`num_Adh`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Adherents`
--

LOCK TABLES `Adherents` WRITE;
/*!40000 ALTER TABLE `Adherents` DISABLE KEYS */;
INSERT INTO `Adherents` VALUES ('OKA1','OUATTARA','KOUNAPETRI',22,'0747963654','Ferke',1),('OKA2','ZOMADI','MARCELLE',25,'0142366353','ABIDJAN',1);
/*!40000 ALTER TABLE `Adherents` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Emprunt`
--

DROP TABLE IF EXISTS `Emprunt`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Emprunt` (
  `num_emp` int unsigned NOT NULL AUTO_INCREMENT,
  `date_sor` int DEFAULT NULL,
  `date_ret` int DEFAULT NULL,
  `date_lim` int DEFAULT NULL,
  `iden_Adh` varchar(30) DEFAULT NULL,
  `iden_liv` varchar(30) DEFAULT NULL,
  `statut` tinyint(1) NOT NULL DEFAULT '0',
  PRIMARY KEY (`num_emp`),
  KEY `num_Adh` (`iden_Adh`),
  KEY `num_liv` (`iden_liv`),
  CONSTRAINT `Emprunt_ibfk_1` FOREIGN KEY (`iden_Adh`) REFERENCES `Adherents` (`num_Adh`),
  CONSTRAINT `Emprunt_ibfk_2` FOREIGN KEY (`iden_liv`) REFERENCES `livres` (`num_liv`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Emprunt`
--

LOCK TABLES `Emprunt` WRITE;
/*!40000 ALTER TABLE `Emprunt` DISABLE KEYS */;
INSERT INTO `Emprunt` VALUES (1,1646764938,0,1582285558,'OKA1','liv3',0),(2,1646764991,0,778669759,'OKA2','liv1',0);
/*!40000 ALTER TABLE `Emprunt` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `livres`
--

DROP TABLE IF EXISTS `livres`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `livres` (
  `num_liv` varchar(30) NOT NULL,
  `titre` varchar(50) NOT NULL,
  `auteur` varchar(100) NOT NULL,
  `mot_cle` varchar(100) DEFAULT NULL,
  `date_par` int DEFAULT NULL,
  `nb_exem` int DEFAULT NULL,
  PRIMARY KEY (`num_liv`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `livres`
--

LOCK TABLES `livres` WRITE;
/*!40000 ALTER TABLE `livres` DISABLE KEYS */;
INSERT INTO `livres` VALUES ('liv1','C','DIABY','Informatique',2022,15),('liv2','Algorithmes','DIABY','info',2018,32),('liv3','NoSQL','KANGA','NoSQL',2010,50),('liv5','Structure','PANDRY','Algo',2019,25);
/*!40000 ALTER TABLE `livres` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2022-03-30  4:46:07
