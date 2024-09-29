-- Create table if not exists with a placeholder for the table name

CREATE TABLE IF NOT EXISTS {{table_name}} (
  `TcNo`                 VARCHAR,
  `TcDate`               VARCHAR,
  `PartNo`               INTEGER,
  `PartName`                CHAR,
  `PartyName`            VARCHAR,
  `SupplierCode`            CHAR,
  `BatchNo`                 CHAR,
  `ChallanQuantity`     SMALLINT,
  `ChallanDate`             DATE,
  `Resistance1Value`       FLOAT,
  `Resistance1Status`      FLOAT,
  `Resistance2Value`       FLOAT,
  `Resistance2Status`      FLOAT,
  `Inductance1Value`       FLOAT,
  `Inductance1Status`      FLOAT,
  `Inductance2Value`       FLOAT,
  `Inductance2Status`      FLOAT,
  `Frequency1Value`        FLOAT,
  `Frequency2Value`        FLOAT,
  `Voltage1NoLoadValue`    FLOAT,
  `Voltage1NoLoadStatus`   FLOAT,
  `Voltage2NoLoadValue`    FLOAT,
  `Voltage2NoLoadStatus`   FLOAT,
  `Voltage1-10kLoadValue`  FLOAT,
  `Voltage1-10kLoadStatus` FLOAT,
  `Voltage2-10kLoadValue`  FLOAT,
  `Voltage2-10kLoadStatus` FLOAT,
  `Voltage1-3k3LoadValue`  FLOAT,
  `Voltage1-3k3LoadStatus` FLOAT,
  `Voltage2-3k3LoadValue`  FLOAT,
  `Voltage2-3k3Loadstatus` FLOAT,
);
