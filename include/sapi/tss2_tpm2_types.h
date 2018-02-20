//**********************************************************************;
// Copyright (c) 2015, Intel Corporation
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
// this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
// this list of conditions and the following disclaimer in the documentation
// and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
// THE POSSIBILITY OF SUCH DAMAGE.
//**********************************************************************;

#ifndef TSS2_TPMS_TYPES_H
#define TSS2_TPMS_TYPES_H

#ifndef TSS2_API_VERSION_1_1_1_1
#error Version mismatch among TSS2 header files. \
       Do not include this file, #include <sapi/tpm20.h> instead.
#endif  /* TSS2_API_VERSION_1_1_1_1 */

#include <stdint.h>

/* Defines from previous implementation.h; DEPRECATED */
#define  YES      1
#define  NO       0
#define TPM2_MAX_COMMAND_SIZE		4096	/* maximum size of a command */
#define TPM2_MAX_RESPONSE_SIZE		4096	/* maximum size of a response */
#define TPM2_MAX_SESSION_NUM 		3	/* this is the current maximum value */

/* TPM constants for buffer sizes */
#define TPM2_NUM_PCR_BANKS 3
#define TPM2_MAX_DIGEST_BUFFER 1024
#define TPM2_MAX_NV_BUFFER_SIZE 2048
#define TPM2_MAX_PCRS 32
#define TPM2_MAX_ALG_LIST_SIZE 128
#define TPM2_MAX_CAP_CC 256
#define TPM2_MAX_CAP_BUFFER 1024
#define TPM2_MAX_CONTEXT_SIZE 5120

/* Hash algorithm sizes */
#define TPM2_SHA_DIGEST_SIZE 20
#define TPM2_SHA1_DIGEST_SIZE 20
#define TPM2_SHA256_DIGEST_SIZE 32
#define TPM2_SHA384_DIGEST_SIZE 48
#define TPM2_SHA512_DIGEST_SIZE 64
#define TPM2_SM3_256_DIGEST_SIZE 32

/* Encryption algorithm sizes */
#define TPM2_MAX_SYM_BLOCK_SIZE 16
#define TPM2_MAX_SYM_DATA 256
#define TPM2_MAX_ECC_KEY_BYTES 128
#define TPM2_MAX_SYM_KEY_BYTES 32
#define TPM2_MAX_RSA_KEY_BYTES 512

/* Capability buffer sizes*/ 
#define TPM2_LABEL_MAX_BUFFER 32
#define TPM2_PCR_SELECT_MAX ((TPM2_MAX_PCRS+7)/8)
#define TPM2_MAX_CAP_HANDLES ((TPM2_MAX_CAP_BUFFER-sizeof(TPM2_CAP)-\
                               sizeof(UINT32))/sizeof(TPM2_HANDLE))
#define TPM2_MAX_CAP_ALGS ((TPM2_MAX_CAP_BUFFER-sizeof(TPM2_CAP)-\
                            sizeof(UINT32))/sizeof(TPMS_ALG_PROPERTY))
#define TPM2_MAX_TPM_PROPERTIES ((TPM2_MAX_CAP_BUFFER-sizeof(TPM2_CAP)-\
                                  sizeof(UINT32))/sizeof(TPMS_TAGGED_PROPERTY))
#define TPM2_MAX_PCR_PROPERTIES ((TPM2_MAX_CAP_BUFFER-sizeof(TPM2_CAP)-\
                                 sizeof(UINT32))/sizeof(TPMS_TAGGED_PCR_SELECT)) 
#define TPM2_MAX_ECC_CURVES ((TPM2_MAX_CAP_BUFFER-sizeof(TPM2_CAP)-\
                              sizeof(UINT32))/sizeof(TPM2_ECC_CURVE)) 
#define TPM2_MAX_TAGGED_POLICIES ((TPM2_MAX_CAP_BUFFER-sizeof(TPM2_CAP)-\
                                   sizeof(UINT32))/sizeof(TPMS_TAGGED_POLICY)) 
#define TPM2_PRIVATE_VENDOR_SPECIFIC_BYTES ((TPM2_MAX_RSA_KEY_BYTES/2)*(3+2))

/* Vendor Specific Defines */
#define TPM2_MAX_PTT_PROPERTIES (TPM2_MAX_CAP_BUFFER/sizeof(UINT32))

/* Attached Component Capabilities */
#define TPM2_MAX_AC_CAPABILITIES (TPM2_MAX_CAP_BUFFER/sizeof(TPMS_AC_OUTPUT))

// From TCG Algorithm Registry: Table 3 - Definition of TPM2_ALG_ID Constants
typedef  UINT16             TPM2_ALG_ID;
#define  TPM2_ALG_ERROR               0x0000
#define  TPM2_ALG_RSA                 0x0001
#define  TPM2_ALG_SHA                 0x0004
#define  TPM2_ALG_SHA1                0x0004
#define  TPM2_ALG_HMAC                0x0005
#define  TPM2_ALG_AES                 0x0006
#define  TPM2_ALG_MGF1                0x0007
#define  TPM2_ALG_KEYEDHASH           0x0008
#define  TPM2_ALG_XOR                 0x000A
#define  TPM2_ALG_SHA256              0x000B
#define  TPM2_ALG_SHA384              0x000C
#define  TPM2_ALG_SHA512              0x000D
#define  TPM2_ALG_NULL                0x0010
#define  TPM2_ALG_SM3_256             0x0012
#define  TPM2_ALG_SM4                 0x0013
#define  TPM2_ALG_RSASSA              0x0014
#define  TPM2_ALG_RSAES               0x0015
#define  TPM2_ALG_RSAPSS              0x0016
#define  TPM2_ALG_OAEP                0x0017
#define  TPM2_ALG_ECDSA               0x0018
#define  TPM2_ALG_ECDH                0x0019
#define  TPM2_ALG_ECDAA               0x001A
#define  TPM2_ALG_SM2                 0x001B
#define  TPM2_ALG_ECSCHNORR           0x001C
#define  TPM2_ALG_ECMQV               0x001D
#define  TPM2_ALG_KDF1_SP800_56A      0x0020
#define  TPM2_ALG_KDF2                0x0021
#define  TPM2_ALG_KDF1_SP800_108      0x0022
#define  TPM2_ALG_ECC                 0x0023
#define  TPM2_ALG_SYMCIPHER           0x0025
#define  TPM2_ALG_CAMELLIA            0x0026
#define  TPM2_ALG_CTR                 0x0040
#define  TPM2_ALG_SHA3_256            0x0027
#define  TPM2_ALG_SHA3_384            0x0028
#define  TPM2_ALG_SHA3_512            0x0029
#define  TPM2_ALG_OFB                 0x0041
#define  TPM2_ALG_CBC                 0x0042
#define  TPM2_ALG_CFB                 0x0043
#define  TPM2_ALG_ECB                 0x0044
#define  TPM2_ALG_FIRST               0x0001
#define  TPM2_ALG_LAST                0x0044

//     From TCG Algorithm Registry: Table 3 - Definition of TPM2_ECC_CURVE Constants

typedef  UINT16             TPM2_ECC_CURVE;
#define  TPM2_ECC_NONE         (TPM2_ECC_CURVE)(0x0000)
#define  TPM2_ECC_NIST_P192    (TPM2_ECC_CURVE)(0x0001)
#define  TPM2_ECC_NIST_P224    (TPM2_ECC_CURVE)(0x0002)
#define  TPM2_ECC_NIST_P256    (TPM2_ECC_CURVE)(0x0003)
#define  TPM2_ECC_NIST_P384    (TPM2_ECC_CURVE)(0x0004)
#define  TPM2_ECC_NIST_P521    (TPM2_ECC_CURVE)(0x0005)
#define  TPM2_ECC_BN_P256      (TPM2_ECC_CURVE)(0x0010)
#define  TPM2_ECC_BN_P638      (TPM2_ECC_CURVE)(0x0011)
#define  TPM2_ECC_SM2_P256     (TPM2_ECC_CURVE)(0x0020)

// From TPM 2.0 Part 2: Table 13 - Definition of TPM2_CC Constants
typedef  UINT32             TPM2_CC;
#define  TPM2_CC_NV_UndefineSpaceSpecial       (TPM2_CC)(0x0000011f)
#define TPM2_CC_FIRST TPM2_CC_NV_UndefineSpaceSpecial
#define  TPM2_CC_EvictControl                  (TPM2_CC)(0x00000120)
#define  TPM2_CC_HierarchyControl              (TPM2_CC)(0x00000121)
#define  TPM2_CC_NV_UndefineSpace              (TPM2_CC)(0x00000122)
#define  TPM2_CC_ChangeEPS                     (TPM2_CC)(0x00000124)
#define  TPM2_CC_ChangePPS                     (TPM2_CC)(0x00000125)
#define  TPM2_CC_Clear                         (TPM2_CC)(0x00000126)
#define  TPM2_CC_ClearControl                  (TPM2_CC)(0x00000127)
#define  TPM2_CC_ClockSet                      (TPM2_CC)(0x00000128)
#define  TPM2_CC_HierarchyChangeAuth           (TPM2_CC)(0x00000129)
#define  TPM2_CC_NV_DefineSpace                (TPM2_CC)(0x0000012a)
#define  TPM2_CC_PCR_Allocate                  (TPM2_CC)(0x0000012b)
#define  TPM2_CC_PCR_SetAuthPolicy             (TPM2_CC)(0x0000012c)
#define  TPM2_CC_PP_Commands                   (TPM2_CC)(0x0000012d)
#define  TPM2_CC_SetPrimaryPolicy              (TPM2_CC)(0x0000012e)
#define  TPM2_CC_FieldUpgradeStart             (TPM2_CC)(0x0000012f)
#define  TPM2_CC_ClockRateAdjust               (TPM2_CC)(0x00000130)
#define  TPM2_CC_CreatePrimary                 (TPM2_CC)(0x00000131)
#define  TPM2_CC_NV_GlobalWriteLock            (TPM2_CC)(0x00000132)
#define  TPM2_CC_GetCommandAuditDigest         (TPM2_CC)(0x00000133)
#define  TPM2_CC_NV_Increment                  (TPM2_CC)(0x00000134)
#define  TPM2_CC_NV_SetBits                    (TPM2_CC)(0x00000135)
#define  TPM2_CC_NV_Extend                     (TPM2_CC)(0x00000136)
#define  TPM2_CC_NV_Write                      (TPM2_CC)(0x00000137)
#define  TPM2_CC_NV_WriteLock                  (TPM2_CC)(0x00000138)
#define  TPM2_CC_DictionaryAttackLockReset     (TPM2_CC)(0x00000139)
#define  TPM2_CC_DictionaryAttackParameters    (TPM2_CC)(0x0000013a)
#define  TPM2_CC_NV_ChangeAuth                 (TPM2_CC)(0x0000013b)
#define  TPM2_CC_PCR_Event                     (TPM2_CC)(0x0000013c)
#define  TPM2_CC_PCR_Reset                     (TPM2_CC)(0x0000013d)
#define  TPM2_CC_SequenceComplete              (TPM2_CC)(0x0000013e)
#define  TPM2_CC_SetAlgorithmSet               (TPM2_CC)(0x0000013f)
#define  TPM2_CC_SetCommandCodeAuditStatus     (TPM2_CC)(0x00000140)
#define  TPM2_CC_FieldUpgradeData              (TPM2_CC)(0x00000141)
#define  TPM2_CC_IncrementalSelfTest           (TPM2_CC)(0x00000142)
#define  TPM2_CC_SelfTest                      (TPM2_CC)(0x00000143)
#define  TPM2_CC_Startup                       (TPM2_CC)(0x00000144)
#define  TPM2_CC_Shutdown                      (TPM2_CC)(0x00000145)
#define  TPM2_CC_StirRandom                    (TPM2_CC)(0x00000146)
#define  TPM2_CC_ActivateCredential            (TPM2_CC)(0x00000147)
#define  TPM2_CC_Certify                       (TPM2_CC)(0x00000148)
#define  TPM2_CC_PolicyNV                      (TPM2_CC)(0x00000149)
#define  TPM2_CC_CertifyCreation               (TPM2_CC)(0x0000014a)
#define  TPM2_CC_Duplicate                     (TPM2_CC)(0x0000014b)
#define  TPM2_CC_GetTime                       (TPM2_CC)(0x0000014c)
#define  TPM2_CC_GetSessionAuditDigest         (TPM2_CC)(0x0000014d)
#define  TPM2_CC_NV_Read                       (TPM2_CC)(0x0000014e)
#define  TPM2_CC_NV_ReadLock                   (TPM2_CC)(0x0000014f)
#define  TPM2_CC_ObjectChangeAuth              (TPM2_CC)(0x00000150)
#define  TPM2_CC_PolicySecret                  (TPM2_CC)(0x00000151)
#define  TPM2_CC_Rewrap                        (TPM2_CC)(0x00000152)
#define  TPM2_CC_Create                        (TPM2_CC)(0x00000153)
#define  TPM2_CC_ECDH_ZGen                     (TPM2_CC)(0x00000154)
#define  TPM2_CC_HMAC                          (TPM2_CC)(0x00000155)
#define  TPM2_CC_Import                        (TPM2_CC)(0x00000156)
#define  TPM2_CC_Load                          (TPM2_CC)(0x00000157)
#define  TPM2_CC_Quote                         (TPM2_CC)(0x00000158)
#define  TPM2_CC_RSA_Decrypt                   (TPM2_CC)(0x00000159)
#define  TPM2_CC_HMAC_Start                    (TPM2_CC)(0x0000015b)
#define  TPM2_CC_SequenceUpdate                (TPM2_CC)(0x0000015c)
#define  TPM2_CC_Sign                          (TPM2_CC)(0x0000015d)
#define  TPM2_CC_Unseal                        (TPM2_CC)(0x0000015e)
#define  TPM2_CC_PolicySigned                  (TPM2_CC)(0x00000160)
#define  TPM2_CC_ContextLoad                   (TPM2_CC)(0x00000161)
#define  TPM2_CC_ContextSave                   (TPM2_CC)(0x00000162)
#define  TPM2_CC_ECDH_KeyGen                   (TPM2_CC)(0x00000163)
#define  TPM2_CC_EncryptDecrypt                (TPM2_CC)(0x00000164)
#define  TPM2_CC_FlushContext                  (TPM2_CC)(0x00000165)
#define  TPM2_CC_LoadExternal                  (TPM2_CC)(0x00000167)
#define  TPM2_CC_MakeCredential                (TPM2_CC)(0x00000168)
#define  TPM2_CC_NV_ReadPublic                 (TPM2_CC)(0x00000169)
#define  TPM2_CC_PolicyAuthorize               (TPM2_CC)(0x0000016a)
#define  TPM2_CC_PolicyAuthValue               (TPM2_CC)(0x0000016b)
#define  TPM2_CC_PolicyCommandCode             (TPM2_CC)(0x0000016c)
#define  TPM2_CC_PolicyCounterTimer            (TPM2_CC)(0x0000016d)
#define  TPM2_CC_PolicyCpHash                  (TPM2_CC)(0x0000016e)
#define  TPM2_CC_PolicyLocality                (TPM2_CC)(0x0000016f)
#define  TPM2_CC_PolicyNameHash                (TPM2_CC)(0x00000170)
#define  TPM2_CC_PolicyOR                      (TPM2_CC)(0x00000171)
#define  TPM2_CC_PolicyTicket                  (TPM2_CC)(0x00000172)
#define  TPM2_CC_ReadPublic                    (TPM2_CC)(0x00000173)
#define  TPM2_CC_RSA_Encrypt                   (TPM2_CC)(0x00000174)
#define  TPM2_CC_StartAuthSession              (TPM2_CC)(0x00000176)
#define  TPM2_CC_VerifySignature               (TPM2_CC)(0x00000177)
#define  TPM2_CC_ECC_Parameters                (TPM2_CC)(0x00000178)
#define  TPM2_CC_FirmwareRead                  (TPM2_CC)(0x00000179)
#define  TPM2_CC_GetCapability                 (TPM2_CC)(0x0000017a)
#define  TPM2_CC_GetRandom                     (TPM2_CC)(0x0000017b)
#define  TPM2_CC_GetTestResult                 (TPM2_CC)(0x0000017c)
#define  TPM2_CC_Hash                          (TPM2_CC)(0x0000017d)
#define  TPM2_CC_PCR_Read                      (TPM2_CC)(0x0000017e)
#define  TPM2_CC_PolicyPCR                     (TPM2_CC)(0x0000017f)
#define  TPM2_CC_PolicyRestart                 (TPM2_CC)(0x00000180)
#define  TPM2_CC_ReadClock                     (TPM2_CC)(0x00000181)
#define  TPM2_CC_PCR_Extend                    (TPM2_CC)(0x00000182)
#define  TPM2_CC_PCR_SetAuthValue              (TPM2_CC)(0x00000183)
#define  TPM2_CC_NV_Certify                    (TPM2_CC)(0x00000184)
#define  TPM2_CC_EventSequenceComplete         (TPM2_CC)(0x00000185)
#define  TPM2_CC_HashSequenceStart             (TPM2_CC)(0x00000186)
#define  TPM2_CC_PolicyPhysicalPresence        (TPM2_CC)(0x00000187)
#define  TPM2_CC_PolicyDuplicationSelect       (TPM2_CC)(0x00000188)
#define  TPM2_CC_PolicyGetDigest               (TPM2_CC)(0x00000189)
#define  TPM2_CC_TestParms                     (TPM2_CC)(0x0000018a)
#define  TPM2_CC_Commit                        (TPM2_CC)(0x0000018b)
#define  TPM2_CC_PolicyPassword                (TPM2_CC)(0x0000018c)
#define  TPM2_CC_ZGen_2Phase                   (TPM2_CC)(0x0000018d)
#define  TPM2_CC_EC_Ephemeral                  (TPM2_CC)(0x0000018e)
#define  TPM2_CC_PolicyNvWritten               (TPM2_CC)(0x0000018f)
#define  TPM2_CC_PolicyTemplate                (TPM2_CC)(0x00000190)
#define  TPM2_CC_CreateLoaded                  (TPM2_CC)(0x00000191)
#define  TPM2_CC_PolicyAuthorizeNV             (TPM2_CC)(0x00000192)
#define  TPM2_CC_EncryptDecrypt2               (TPM2_CC)(0x00000193)
#define  TPM2_CC_AC_GetCapability              (TPM2_CC)(0x00000194)
#define  TPM2_CC_AC_Send                       (TPM2_CC)(0x00000195)
#define  TPM2_CC_Policy_AC_SendSelect          (TPM2_CC)(0x00000196)
#define  TPM2_CC_LAST                          (TPM2_CC)(0x00000196)
#define  TPM2_CC_Vendor_TCG_Test               (TPM2_CC)(0x20000000)

/* Table 5  Definition of Types for Documentation Clarity */
typedef	UINT32	TPM2_ALGORITHM_ID;	 /* this is the 1.2 compatible form of the TPM2_ALG_ID  */
typedef	UINT32	TPM2_MODIFIER_INDICATOR;	 /*   */
typedef	UINT32	TPM2_AUTHORIZATION_SIZE;	 /* the authorizationSize parameter in a command  */
typedef	UINT32	TPM2_PARAMETER_SIZE;	 /* the parameterSize parameter in a command  */
typedef	UINT16	TPM2_KEY_SIZE;	 /* a key size in octets  */
typedef	UINT16	TPM2_KEY_BITS;	 /* a key size in bits  */

/* Table 6  Definition of UINT32 TPM2_SPEC Constants <> */
typedef	UINT32 TPM2_SPEC;
#define	TPM2_SPEC_FAMILY	(0x322E3000 )	 /* ASCII 2.0 with null terminator  */
#define	TPM2_SPEC_LEVEL	(00 )	 /* the level number for the specification  */
#define	TPM2_SPEC_VERSION	(126 )	 /* the version number of the spec 001.26 * 100  */
#define	TPM2_SPEC_YEAR	(2015 )	 /* the year of the version  */
#define	TPM2_SPEC_DAY_OF_YEAR	(233 )	 /* the day of the year August 21 2015  */

/* Table 7  Definition of UINT32 TPM2_GENERATED Constants <O> */
typedef	UINT32 TPM2_GENERATED;
#define	TPM2_GENERATED_VALUE	(0xff544347 )	 /* 0xFF TCG FF 54 43 4716  */

/* Table 16  Definition of UINT32 TPM2_RC Constants Actions <OUT> */
typedef	UINT32 TPM2_RC;
#define	TPM2_RC_SUCCESS	(0x000 )	 /*   */
#define	TPM2_RC_BAD_TAG	(0x01E )	 /* defined for compatibility with TPM 1.2  */
#define	TPM2_RC_VER1	(0x100 )	 /* set for all format 0 response codes  */
#define	TPM2_RC_INITIALIZE	(TPM2_RC_VER1 + 0x000 )	 /* TPM not initialized by TPM2_Startup or already initialized   */
#define	TPM2_RC_FAILURE	(TPM2_RC_VER1 + 0x001 )	 /* commands not being accepted because of a TPM failureNOTE	This may be returned by TPM2_GetTestResult as the testResult parameter.  */
#define	TPM2_RC_SEQUENCE	(TPM2_RC_VER1 + 0x003 )	 /* improper use of a sequence handle   */
#define	TPM2_RC_PRIVATE	(TPM2_RC_VER1 + 0x00B )	 /* not currently used  */
#define	TPM2_RC_HMAC	(TPM2_RC_VER1 + 0x019 )	 /* not currently used  */
#define	TPM2_RC_DISABLED	(TPM2_RC_VER1 + 0x020 )	 /* the command is disabled  */
#define	TPM2_RC_EXCLUSIVE	(TPM2_RC_VER1 + 0x021 )	 /* command failed because audit sequence required exclusivity  */
#define	TPM2_RC_AUTH_TYPE	(TPM2_RC_VER1 + 0x024 )	 /* authorization handle is not correct for command  */
#define	TPM2_RC_AUTH_MISSING	(TPM2_RC_VER1 + 0x025 )	 /* command requires an authorization session for handle and it is not present.  */
#define	TPM2_RC_POLICY	(TPM2_RC_VER1 + 0x026 )	 /* policy failure in math operation or an invalid authPolicy value  */
#define	TPM2_RC_PCR	(TPM2_RC_VER1 + 0x027 )	 /* PCR check fail  */
#define	TPM2_RC_PCR_CHANGED	(TPM2_RC_VER1 + 0x028 )	 /* PCR have changed since checked.  */
#define	TPM2_RC_UPGRADE	(TPM2_RC_VER1 + 0x02D )	 /* for all commands other than TPM2_FieldUpgradeData this code indicates that the TPM is in field upgrade mode for TPM2_FieldUpgradeData this code indicates that the TPM is not in field upgrade mode  */
#define	TPM2_RC_TOO_MANY_CONTEXTS	(TPM2_RC_VER1 + 0x02E )	 /* context ID counter is at maximum.  */
#define	TPM2_RC_AUTH_UNAVAILABLE	(TPM2_RC_VER1 + 0x02F )	 /* authValue or authPolicy is not available for selected entity.  */
#define	TPM2_RC_REBOOT	(TPM2_RC_VER1 + 0x030 )	 /* a _TPM_Init and StartupCLEAR is required before the TPM can resume operation.  */
#define	TPM2_RC_UNBALANCED	(TPM2_RC_VER1 + 0x031 )	 /* the protection algorithms hash and symmetric are not reasonably balanced. The digest size of the hash must be larger than the key size of the symmetric algorithm.  */
#define	TPM2_RC_COMMAND_SIZE	(TPM2_RC_VER1 + 0x042 )	 /* command commandSize value is inconsistent with contents of the command buffer either the size is not the same as the octets loaded by the hardware interface layer or the value is not large enough to hold a command header  */
#define	TPM2_RC_COMMAND_CODE	(TPM2_RC_VER1 + 0x043 )	 /* command code not supported  */
#define	TPM2_RC_AUTHSIZE	(TPM2_RC_VER1 + 0x044 )	 /* the value of authorizationSize is out of range or the number of octets in the Authorization Area is greater than required  */
#define	TPM2_RC_AUTH_CONTEXT	(TPM2_RC_VER1 + 0x045 )	 /* use of an authorization session with a context command or another command that cannot have an authorization session.  */
#define	TPM2_RC_NV_RANGE	(TPM2_RC_VER1 + 0x046 )	 /* NV offset+size is out of range.  */
#define	TPM2_RC_NV_SIZE	(TPM2_RC_VER1 + 0x047 )	 /* Requested allocation size is larger than allowed.  */
#define	TPM2_RC_NV_LOCKED	(TPM2_RC_VER1 + 0x048 )	 /* NV access locked.  */
#define	TPM2_RC_NV_AUTHORIZATION	(TPM2_RC_VER1 + 0x049 )	 /* NV access authorization fails in command actions this failure does not affect lockout.action  */
#define	TPM2_RC_NV_UNINITIALIZED	(TPM2_RC_VER1 + 0x04A )	 /* an NV Index is used before being initialized or the state saved by TPM2_ShutdownSTATE could not be restored  */
#define	TPM2_RC_NV_SPACE	(TPM2_RC_VER1 + 0x04B )	 /* insufficient space for NV allocation  */
#define	TPM2_RC_NV_DEFINED	(TPM2_RC_VER1 + 0x04C )	 /* NV Index or persistent object already defined  */
#define	TPM2_RC_BAD_CONTEXT	(TPM2_RC_VER1 + 0x050 )	 /* context in TPM2_ContextLoad is not valid  */
#define	TPM2_RC_CPHASH	(TPM2_RC_VER1 + 0x051 )	 /* cpHash value already set or not correct for use  */
#define	TPM2_RC_PARENT	(TPM2_RC_VER1 + 0x052 )	 /* handle for parent is not a valid parent  */
#define	TPM2_RC_NEEDS_TEST	(TPM2_RC_VER1 + 0x053 )	 /* some function needs testing.  */
#define	TPM2_RC_NO_RESULT	(TPM2_RC_VER1 + 0x054 )	 /* returned when an internal function cannot process a request due to an unspecified problem. This code is usually related to invalid parameters that are not properly filtered by the input unmarshaling code.  */
#define	TPM2_RC_SENSITIVE	(TPM2_RC_VER1 + 0x055 )	 /* the sensitive area did not unmarshal correctly after decryption  this code is used in lieu of the other unmarshaling errors so that an attacker cannot determine where the unmarshaling error occurred  */
#define	TPM2_RC_MAX_FM0	(TPM2_RC_VER1 + 0x07F )	 /* largest version 1 code that is not a warning  */
#define	TPM2_RC_FMT1	(0x080 )	 /* This bit is SET in all format 1 response codesThe codes in this group may have a value added to them to indicate the handle session or parameter to which they apply.  */
#define	TPM2_RC_ASYMMETRIC	(TPM2_RC_FMT1 + 0x001 )	 /* asymmetric algorithm not supported or not correct  */
#define	TPM2_RC_ATTRIBUTES	(TPM2_RC_FMT1 + 0x002 )	 /* inconsistent attributes  */
#define	TPM2_RC_HASH	(TPM2_RC_FMT1 + 0x003 )	 /* hash algorithm not supported or not appropriate   */
#define	TPM2_RC_VALUE	(TPM2_RC_FMT1 + 0x004 )	 /* value is out of range or is not correct for the context  */
#define	TPM2_RC_HIERARCHY	(TPM2_RC_FMT1 + 0x005 )	 /* hierarchy is not enabled or is not correct for the use  */
#define	TPM2_RC_KEY_SIZE	(TPM2_RC_FMT1 + 0x007 )	 /* key size is not supported  */
#define	TPM2_RC_MGF	(TPM2_RC_FMT1 + 0x008 )	 /* mask generation function not supported  */
#define	TPM2_RC_MODE	(TPM2_RC_FMT1 + 0x009 )	 /* mode of operation not supported  */
#define	TPM2_RC_TYPE	(TPM2_RC_FMT1 + 0x00A )	 /* the type of the value is not appropriate for the use  */
#define	TPM2_RC_HANDLE	(TPM2_RC_FMT1 + 0x00B )	 /* the handle is not correct for the use  */
#define	TPM2_RC_KDF	(TPM2_RC_FMT1 + 0x00C )	 /* unsupported key derivation function or function not appropriate for use  */
#define	TPM2_RC_RANGE	(TPM2_RC_FMT1 + 0x00D )	 /* value was out of allowed range.  */
#define	TPM2_RC_AUTH_FAIL	(TPM2_RC_FMT1 + 0x00E )	 /* the authorization HMAC check failed and DA counter incremented   */
#define	TPM2_RC_NONCE	(TPM2_RC_FMT1 + 0x00F )	 /* invalid nonce size or nonce value mismatch  */
#define	TPM2_RC_PP	(TPM2_RC_FMT1 + 0x010 )	 /* authorization requires assertion of PP  */
#define	TPM2_RC_SCHEME	(TPM2_RC_FMT1 + 0x012 )	 /* unsupported or incompatible scheme  */
#define	TPM2_RC_SIZE	(TPM2_RC_FMT1 + 0x015 )	 /* structure is the wrong size  */
#define	TPM2_RC_SYMMETRIC	(TPM2_RC_FMT1 + 0x016 )	 /* unsupported symmetric algorithm or key size or not appropriate for instance  */
#define	TPM2_RC_TAG	(TPM2_RC_FMT1 + 0x017 )	 /* incorrect structure tag  */
#define	TPM2_RC_SELECTOR	(TPM2_RC_FMT1 + 0x018 )	 /* union selector is incorrect  */
#define	TPM2_RC_INSUFFICIENT	(TPM2_RC_FMT1 + 0x01A )	 /* the TPM was unable to unmarshal a value because there were not enough octets in the input buffer   */
#define	TPM2_RC_SIGNATURE	(TPM2_RC_FMT1 + 0x01B )	 /* the signature is not valid  */
#define	TPM2_RC_KEY	(TPM2_RC_FMT1 + 0x01C )	 /* key fields are not compatible with the selected use  */
#define	TPM2_RC_POLICY_FAIL	(TPM2_RC_FMT1 + 0x01D )	 /* a policy check failed  */
#define	TPM2_RC_INTEGRITY	(TPM2_RC_FMT1 + 0x01F )	 /* integrity check failed   */
#define	TPM2_RC_TICKET	(TPM2_RC_FMT1 + 0x020 )	 /* invalid ticket   */
#define	TPM2_RC_RESERVED_BITS	(TPM2_RC_FMT1 + 0x021 )	 /* reserved bits not set to zero as required  */
#define	TPM2_RC_BAD_AUTH	(TPM2_RC_FMT1 + 0x022 )	 /* authorization failure without DA implications  */
#define	TPM2_RC_EXPIRED	(TPM2_RC_FMT1 + 0x023 )	 /* the policy has expired  */
#define	TPM2_RC_POLICY_CC	(TPM2_RC_FMT1 + 0x024 )	 /* the commandCode in the policy is not the commandCode of the command or the command code in a policy command references a command that is not implemented  */
#define	TPM2_RC_BINDING	(TPM2_RC_FMT1 + 0x025 )	 /* public and sensitive portions of an object are not cryptographically bound  */
#define	TPM2_RC_CURVE	(TPM2_RC_FMT1 + 0x026 )	 /* curve not supported  */
#define	TPM2_RC_ECC_POINT	(TPM2_RC_FMT1 + 0x027 )	 /* point is not on the required curve.  */
#define	TPM2_RC_WARN	(0x900 )	 /* set for warning response codes  */
#define	TPM2_RC_CONTEXT_GAP	(TPM2_RC_WARN + 0x001 )	 /* gap for context ID is too large  */
#define	TPM2_RC_OBJECT_MEMORY	(TPM2_RC_WARN + 0x002 )	 /* out of memory for object contexts  */
#define	TPM2_RC_SESSION_MEMORY	(TPM2_RC_WARN + 0x003 )	 /* out of memory for session contexts  */
#define	TPM2_RC_MEMORY	(TPM2_RC_WARN + 0x004 )	 /* out of shared objectsession memory or need space for internal operations  */
#define	TPM2_RC_SESSION_HANDLES	(TPM2_RC_WARN + 0x005 )	 /* out of session handles  a session must be flushed before a new session may be created  */
#define	TPM2_RC_OBJECT_HANDLES	(TPM2_RC_WARN + 0x006 )	 /* out of object handles  the handle space for objects is depleted and a reboot is requiredNOTE	This cannot occur on the reference implementation.NOTE     There is no reason why an implementation would implement a design that would deplete handle space. Platform specifications are encouraged to forbid it.  */
#define	TPM2_RC_LOCALITY	(TPM2_RC_WARN + 0x007 )	 /* bad locality  */
#define	TPM2_RC_YIELDED	(TPM2_RC_WARN + 0x008 )	 /* the TPM has suspended operation on the command forward progress was made and the command may be retriedSee TPM 2.0 Part 1 Multitasking.NOTE	This cannot occur on the reference implementation.  */
#define	TPM2_RC_CANCELED	(TPM2_RC_WARN + 0x009 )	 /* the command was canceled  */
#define	TPM2_RC_TESTING	(TPM2_RC_WARN + 0x00A )	 /* TPM is performing selftests  */
#define	TPM2_RC_REFERENCE_H0	(TPM2_RC_WARN + 0x010 )	 /* the 1st handle in the handle area references a transient object or session that is not loaded  */
#define	TPM2_RC_REFERENCE_H1	(TPM2_RC_WARN + 0x011 )	 /* the 2nd handle in the handle area references a transient object or session that is not loaded  */
#define	TPM2_RC_REFERENCE_H2	(TPM2_RC_WARN + 0x012 )	 /* the 3rd handle in the handle area references a transient object or session that is not loaded  */
#define	TPM2_RC_REFERENCE_H3	(TPM2_RC_WARN + 0x013 )	 /* the 4th handle in the handle area references a transient object or session that is not loaded  */
#define	TPM2_RC_REFERENCE_H4	(TPM2_RC_WARN + 0x014 )	 /* the 5th handle in the handle area references a transient object or session that is not loaded  */
#define	TPM2_RC_REFERENCE_H5	(TPM2_RC_WARN + 0x015 )	 /* the 6th handle in the handle area references a transient object or session that is not loaded  */
#define	TPM2_RC_REFERENCE_H6	(TPM2_RC_WARN + 0x016 )	 /* the 7th handle in the handle area references a transient object or session that is not loaded  */
#define	TPM2_RC_REFERENCE_S0	(TPM2_RC_WARN + 0x018 )	 /* the 1st authorization session handle references a session that is not loaded  */
#define	TPM2_RC_REFERENCE_S1	(TPM2_RC_WARN + 0x019 )	 /* the 2nd authorization session handle references a session that is not loaded  */
#define	TPM2_RC_REFERENCE_S2	(TPM2_RC_WARN + 0x01A )	 /* the 3rd authorization session handle references a session that is not loaded  */
#define	TPM2_RC_REFERENCE_S3	(TPM2_RC_WARN + 0x01B )	 /* the 4th authorization session handle references a session that is not loaded  */
#define	TPM2_RC_REFERENCE_S4	(TPM2_RC_WARN + 0x01C )	 /* the 5th session handle references a session that is not loaded  */
#define	TPM2_RC_REFERENCE_S5	(TPM2_RC_WARN + 0x01D )	 /* the 6th session handle references a session that is not loaded  */
#define	TPM2_RC_REFERENCE_S6	(TPM2_RC_WARN + 0x01E )	 /* the 7th authorization session handle references a session that is not loaded  */
#define	TPM2_RC_NV_RATE	(TPM2_RC_WARN + 0x020 )	 /* the TPM is ratelimiting accesses to prevent wearout of NV  */
#define	TPM2_RC_LOCKOUT	(TPM2_RC_WARN + 0x021 )	 /* authorizations for objects subject to DA protection are not allowed at this time because the TPM is in DA lockout mode  */
#define	TPM2_RC_RETRY	(TPM2_RC_WARN + 0x022 )	 /* the TPM was not able to start the command  */
#define	TPM2_RC_NV_UNAVAILABLE	(TPM2_RC_WARN + 0x023 )	 /* the command may require writing of NV and NV is not current accessible  */
#define	TPM2_RC_NOT_USED	(TPM2_RC_WARN + 0x7F )	 /* this value is reserved and shall not be returned by the TPM  */
#define	TPM2_RC_H	(0x000 )	 /* add to a handlerelated error  */
#define	TPM2_RC_P	(0x040 )	 /* add to a parameterrelated error  */
#define	TPM2_RC_S	(0x800 )	 /* add to a sessionrelated error  */
#define	TPM2_RC_1	(0x100 )	 /* add to a parameter handle or sessionrelated error  */
#define	TPM2_RC_2	(0x200 )	 /* add to a parameter handle or sessionrelated error  */
#define	TPM2_RC_3	(0x300 )	 /* add to a parameter handle or sessionrelated error  */
#define	TPM2_RC_4	(0x400 )	 /* add to a parameter handle or sessionrelated error  */
#define	TPM2_RC_5	(0x500 )	 /* add to a parameter handle or sessionrelated error  */
#define	TPM2_RC_6	(0x600 )	 /* add to a parameter handle or sessionrelated error  */
#define	TPM2_RC_7	(0x700 )	 /* add to a parameter handle or sessionrelated error  */
#define	TPM2_RC_8	(0x800 )	 /* add to a parameterrelated error  */
#define	TPM2_RC_9	(0x900 )	 /* add to a parameterrelated error  */
#define	TPM2_RC_A	(0xA00 )	 /* add to a parameterrelated error  */
#define	TPM2_RC_B	(0xB00 )	 /* add to a parameterrelated error  */
#define	TPM2_RC_C	(0xC00 )	 /* add to a parameterrelated error  */
#define	TPM2_RC_D	(0xD00 )	 /* add to a parameterrelated error  */
#define	TPM2_RC_E	(0xE00 )	 /* add to a parameterrelated error  */
#define	TPM2_RC_F	(0xF00 )	 /* add to a parameterrelated error  */
#define	TPM2_RC_N_MASK	(0xF00 )	 /* number mask  */

/* Table 17  Definition of INT8 TPM2_CLOCK_ADJUST Constants <IN> */
typedef	INT8 TPM2_CLOCK_ADJUST;
#define	TPM2_CLOCK_COARSE_SLOWER	(-3 )	 /* Slow the Clock update rate by one coarse adjustment step.  */
#define	TPM2_CLOCK_MEDIUM_SLOWER	(-2 )	 /* Slow the Clock update rate by one medium adjustment step.  */
#define	TPM2_CLOCK_FINE_SLOWER	(-1 )	 /* Slow the Clock update rate by one fine adjustment step.  */
#define	TPM2_CLOCK_NO_CHANGE	(0 )	 /* No change to the Clock update rate.  */
#define	TPM2_CLOCK_FINE_FASTER	(1 )	 /* Speed the Clock update rate by one fine adjustment step.  */
#define	TPM2_CLOCK_MEDIUM_FASTER	(2 )	 /* Speed the Clock update rate by one medium adjustment step.  */
#define	TPM2_CLOCK_COARSE_FASTER	(3 )	 /* Speed the Clock update rate by one coarse adjustment step.  */

/* Table 18  Definition of UINT16 TPM2_EO Constants <INOUT> */
typedef	UINT16 TPM2_EO;
#define	TPM2_EO_EQ	(0x0000 )	 /* A  B  */
#define	TPM2_EO_NEQ	(0x0001 )	 /* A  B  */
#define	TPM2_EO_SIGNED_GT	(0x0002 )	 /* A > B signed  */
#define	TPM2_EO_UNSIGNED_GT	(0x0003 )	 /* A > B unsigned  */
#define	TPM2_EO_SIGNED_LT	(0x0004 )	 /* A < B signed  */
#define	TPM2_EO_UNSIGNED_LT	(0x0005 )	 /* A < B unsigned  */
#define	TPM2_EO_SIGNED_GE	(0x0006 )	 /* A  B signed  */
#define	TPM2_EO_UNSIGNED_GE	(0x0007 )	 /* A  B unsigned  */
#define	TPM2_EO_SIGNED_LE	(0x0008 )	 /* A  B signed  */
#define	TPM2_EO_UNSIGNED_LE	(0x0009 )	 /* A  B unsigned  */
#define	TPM2_EO_BITSET	(0x000A )	 /* All bits SET in B are SET in A. ABB  */
#define	TPM2_EO_BITCLEAR	(0x000B )	 /* All bits SET in B are CLEAR in A. AB0  */

/* Table 19  Definition of UINT16 TPM2_ST Constants <INOUT S> */
typedef	UINT16 TPM2_ST;
#define	TPM2_ST_RSP_COMMAND	(0x00C4 )	 /* tag value for a response used when there is an error in the tag. This is also the value returned from a TPM 1.2 when an error occurs. This value is used in this specification because an error in the command tag may prevent determination of the family. When this tag is used in the response the response code will be TPM2_RC_BAD_TAG 0 1E16 which has the same numeric value as the TPM 1.2 response code for TPM_BADTAG.NOTE	In a previously published version of this specification TPM2_RC_BAD_TAG was incorrectly assigned a value of 0x030 instead of 30 0x01e. Some implementations my return the old value instead of the new value.   */
#define	TPM2_ST_NULL	(0X8000 )	 /* no structure type specified  */
#define	TPM2_ST_NO_SESSIONS	(0x8001 )	 /* tag value for a commandresponse for a command defined in this specification indicating that the commandresponse has no attached sessions and no authorizationSizeparameterSize value is presentIf the responseCode from the TPM is not TPM2_RC_SUCCESS then the response tag shall have this value.  */
#define	TPM2_ST_SESSIONS	(0x8002 )	 /* tag value for a commandresponse for a command defined in this specification indicating that the commandresponse has one or more attached sessions and the authorizationSizeparameterSize field is present  */
#define	TPM2_ST_RESERVED1	(0x8003 )	 /* When used between application software and the TPM resource manager this tag indicates that the command has no sessions and the handles are using the Name format rather than the 32bit handle format.NOTE 1	The response to application software will have a tag of TPM2_ST_NO_SESSIONS.Between the TRM and TPM this tag would occur in a response from a TPM that overlaps the tag parameter of a request with the tag parameter of a response when the response has no associated sessions.NOTE 2	This tag is not used by all TPM or TRM implementations.  */
#define	TPM2_ST_RESERVED2	(0x8004 )	 /* When used between application software and the TPM resource manager this tag indicates that the command has sessions and the handles are using the Name format rather than the 32bit handle format.NOTE 1	If the command completes successfully the response to application software will have a tag of TPM2_ST_SESSIONS.Between the TRM and TPM would occur in a response from a TPM that overlaps the tag parameter of a request with the tag parameter of a response when the response has authorization sessions.NOTE 2	This tag is not used by all TPM or TRM implementations.  */
#define	TPM2_ST_ATTEST_NV	(0x8014 )	 /* tag for an attestation structure  */
#define	TPM2_ST_ATTEST_COMMAND_AUDIT	(0x8015 )	 /* tag for an attestation structure  */
#define	TPM2_ST_ATTEST_SESSION_AUDIT	(0x8016 )	 /* tag for an attestation structure  */
#define	TPM2_ST_ATTEST_CERTIFY	(0x8017 )	 /* tag for an attestation structure  */
#define	TPM2_ST_ATTEST_QUOTE	(0x8018 )	 /* tag for an attestation structure  */
#define	TPM2_ST_ATTEST_TIME	(0x8019 )	 /* tag for an attestation structure  */
#define	TPM2_ST_ATTEST_CREATION	(0x801A )	 /* tag for an attestation structure  */
#define	TPM2_ST_RESERVED3	(0x801B )	 /* do not use NOTE	This was previously assigned to TPM2_ST_ATTEST_NV. The tag is changed because the structure has changed  */
#define	TPM2_ST_CREATION	(0x8021 )	 /* tag for a ticket type  */
#define	TPM2_ST_VERIFIED	(0x8022 )	 /* tag for a ticket type  */
#define	TPM2_ST_AUTH_SECRET	(0x8023 )	 /* tag for a ticket type  */
#define	TPM2_ST_HASHCHECK	(0x8024 )	 /* tag for a ticket type  */
#define	TPM2_ST_AUTH_SIGNED	(0x8025 )	 /* tag for a ticket type  */
#define	TPM2_ST_FU_MANIFEST	(0x8029 )	 /* tag for a structure describing a Field Upgrade Policy  */

/* Table 20  Definition of UINT16 TPM2_SU Constants <IN> */
typedef	UINT16 TPM2_SU;
#define	TPM2_SU_CLEAR	(0x0000 )	 /* on TPM2_Shutdown indicates that the TPM should prepare for loss of power and save state required for an orderly startup TPM Reset.on TPM2_Startup indicates that the TPM should perform TPM Reset or TPM Restart   */
#define	TPM2_SU_STATE	(0x0001 )	 /* on TPM2_Shutdown indicates that the TPM should prepare for loss of power and save state required for an orderly startup TPM Restart or TPM Resumeon TPM2_Startup indicates that the TPM should restore the state saved by TPM2_ShutdownTPM2_SU_STATE  */

/* Table 21  Definition of UINT8 TPM2_SE Constants <IN> */
typedef	UINT8 TPM2_SE;
#define	TPM2_SE_HMAC	(0x00 )	 /*   */
#define	TPM2_SE_POLICY	(0x01 )	 /*   */
#define	TPM2_SE_TRIAL	(0x03 )	 /* The policy session is being used to compute the policyHash and not for command authorization.This setting modifies some policy commands and prevents session from being used to authorize a command.  */

/* Table 22  Definition of UINT32 TPM2_CAP Constants */
typedef	UINT32 TPM2_CAP;
#define	TPM2_CAP_FIRST	(0x00000000 )	 /*   */
#define	TPM2_CAP_ALGS	(0x00000000 )	 /* TPM2_ALG_ID1  */
#define	TPM2_CAP_HANDLES	(0x00000001 )	 /* TPM2_HANDLE  */
#define	TPM2_CAP_COMMANDS	(0x00000002 )	 /* TPM2_CC  */
#define	TPM2_CAP_PP_COMMANDS	(0x00000003 )	 /* TPM2_CC  */
#define	TPM2_CAP_AUDIT_COMMANDS	(0x00000004 )	 /* TPM2_CC  */
#define	TPM2_CAP_PCRS	(0x00000005 )	 /* reserved  */
#define	TPM2_CAP_TPM_PROPERTIES	(0x00000006 )	 /* TPM2_PT  */
#define	TPM2_CAP_PCR_PROPERTIES	(0x00000007 )	 /* TPM2_PT_PCR  */
#define	TPM2_CAP_ECC_CURVES	(0x00000008 )	 /* TPM2_ECC_CURVE1  */
#define	TPM2_CAP_LAST	(0x00000008 )	 /*   */
#define	TPM2_CAP_VENDOR_PROPERTY	(0x00000100 )	 /* manufacturer specific  */

/* Table 23  Definition of UINT32 TPM2_PT Constants <INOUT S> */
typedef	UINT32 TPM2_PT;
#define	TPM2_PT_NONE	(0x00000000 )	 /* indicates no property type  */
#define	TPM2_PT_GROUP	(0x00000100 )	 /* The number of properties in each group.NOTE 	The first group with any properties is group 1 TPM2_PT_GROUP * 1. Group 0 is reserved.  */
#define	TPM2_PT_FIXED	(TPM2_PT_GROUP * 1 )	 /* the group of fixed properties returned as TPMS_TAGGED_PROPERTYThe values in this group are only changed due to a firmware change in the TPM.  */
#define	TPM2_PT_FAMILY_INDICATOR	(TPM2_PT_FIXED + 0 )	 /* a 4octet character string containing the TPM Family value TPM2_SPEC_FAMILY  */
#define	TPM2_PT_LEVEL	(TPM2_PT_FIXED + 1 )	 /* the level of the specificationNOTE 1	For this specification the level is zero.NOTE 2	The level is on the title page of the specification.  */
#define	TPM2_PT_REVISION	(TPM2_PT_FIXED + 2 )	 /* the specification Revision times 100EXAMPLE	Revision 01.01 would have a value of 101.NOTE	The Revision value is on the title page of the specification.  */
#define	TPM2_PT_DAY_OF_YEAR	(TPM2_PT_FIXED + 3 )	 /* the specification day of year using TCG calendarEXAMPLE	November 15 2010 has a day of year value of 319 00 00 01 3F16.NOTE 	The specification date is on the title page of the specification.  */
#define	TPM2_PT_YEAR	(TPM2_PT_FIXED + 4 )	 /* the specification year using the CEEXAMPLE	The year 2010 has a value of 00 00 07 DA16.NOTE 	The specification date is on the title page of the specification.  */
#define	TPM2_PT_MANUFACTURER	(TPM2_PT_FIXED + 5 )	 /* the vendor ID unique to each TPM manufacturer  */
#define	TPM2_PT_VENDOR_STRING_1	(TPM2_PT_FIXED + 6 )	 /* the first four characters of the vendor ID stringNOTE	When the vendor string is fewer than 16 octets the additional property values do not have to be present. A vendor string of 4 octets can be represented in one 32bit value and no null terminating character is required.  */
#define	TPM2_PT_VENDOR_STRING_2	(TPM2_PT_FIXED + 7 )	 /* the second four characters of the vendor ID string  */
#define	TPM2_PT_VENDOR_STRING_3	(TPM2_PT_FIXED + 8 )	 /* the third four characters of the vendor ID string  */
#define	TPM2_PT_VENDOR_STRING_4	(TPM2_PT_FIXED + 9 )	 /* the fourth four characters of the vendor ID sting  */
#define	TPM2_PT_VENDOR_TPM_TYPE	(TPM2_PT_FIXED + 10 )	 /* vendordefined value indicating the TPM model  */
#define	TPM2_PT_FIRMWARE_VERSION_1	(TPM2_PT_FIXED + 11 )	 /* the mostsignificant 32 bits of a TPM vendorspecific value indicating the version number of the firmware. See 10.12.2 and 10.12.8.  */
#define	TPM2_PT_FIRMWARE_VERSION_2	(TPM2_PT_FIXED + 12 )	 /* the leastsignificant 32 bits of a TPM vendorspecific value indicating the version number of the firmware. See 10.12.2 and 10.12.8.  */
#define	TPM2_PT_INPUT_BUFFER	(TPM2_PT_FIXED + 13 )	 /* the maximum size of a parameter typically a TPM2B_MAX_BUFFER  */
#define	TPM2_PT_TPM2_HR_TRANSIENT_MIN	(TPM2_PT_FIXED + 14 )	 /* the minimum number of transient objects that can be held in TPM RAMNOTE	This minimum shall be no less than the minimum value required by the platformspecific specification to which the TPM is built.  */
#define	TPM2_PT_TPM2_HR_PERSISTENT_MIN	(TPM2_PT_FIXED + 15 )	 /* the minimum number of persistent objects that can be held in TPM NV memoryNOTE	This minimum shall be no less than the minimum value required by the platformspecific specification to which the TPM is built.  */
#define	TPM2_PT_HR_LOADED_MIN	(TPM2_PT_FIXED + 16 )	 /* the minimum number of authorization sessions that can be held in TPM RAM NOTE	This minimum shall be no less than the minimum value required by the platformspecific specification to which the TPM is built.  */
#define	TPM2_PT_ACTIVE_SESSIONS_MAX	(TPM2_PT_FIXED + 17 )	 /* the number of authorization sessions that may be active at a timeA session is active when it has a context associated with its handle. The context may either be in TPM RAM or be context saved.NOTE	This value shall be no less than the minimum value required by the platformspecific specification to which the TPM is built.  */
#define	TPM2_PT_PCR_COUNT	(TPM2_PT_FIXED + 18 )	 /* the number of PCR implementedNOTE	This number is determined by the defined attributes not the number of PCR that are populated.  */
#define	TPM2_PT_PCR_SELECT_MIN	(TPM2_PT_FIXED + 19 )	 /* the minimum number of octets in a TPMS_PCR_SELECT.sizeOfSelectNOTE	This value is not determined by the number of PCR implemented but by the number of PCR required by the platformspecific specification with which the TPM is compliant or by the implementer if not adhering to a platformspecific specification.  */
#define	TPM2_PT_CONTEXT_GAP_MAX	(TPM2_PT_FIXED + 20 )	 /* the maximum allowed difference unsigned between the contextID values of two saved session contextsThis value shall be 2n1 where n is at least 16.  */
#define	TPM2_PT_NV_COUNTERS_MAX	(TPM2_PT_FIXED + 22 )	 /* the maximum number of NV Indexes that are allowed to have the TPM2_NT_COUNTER attributeNOTE	It is allowed for this value to be larger than the number of NV Indexes that can be defined. This would be indicative of a TPM implementation that did not use different implementation technology for different NV Index types.  */
#define	TPM2_PT_NV_INDEX_MAX	(TPM2_PT_FIXED + 23 )	 /* the maximum size of an NV Index data area  */
#define	TPM2_PT_MEMORY	(TPM2_PT_FIXED + 24 )	 /* a TPMA_MEMORY indicating the memory management method for the TPM  */
#define	TPM2_PT_CLOCK_UPDATE	(TPM2_PT_FIXED + 25 )	 /* interval in milliseconds between updates to the copy of TPMS_CLOCK_INFO.clock in NV  */
#define	TPM2_PT_CONTEXT_HASH	(TPM2_PT_FIXED + 26 )	 /* the algorithm used for the integrity HMAC on saved contexts and for hashing the fuData of TPM2_FirmwareRead  */
#define	TPM2_PT_CONTEXT_SYM	(TPM2_PT_FIXED + 27 )	 /* TPM2_ALG_ID the algorithm used for encryption of saved contexts  */
#define	TPM2_PT_CONTEXT_SYM_SIZE	(TPM2_PT_FIXED + 28 )	 /* TPM2_KEY_BITS the size of the key used for encryption of saved contexts  */
#define	TPM2_PT_ORDERLY_COUNT	(TPM2_PT_FIXED + 29 )	 /* the modulus  1 of the count for NV update of an orderly counterThe returned value is MAX_ORDERLY_COUNT.This will have a value of 2N  1 where 1  N  32NOTE	An orderly counter is an NV Index with an TPM2_NT of TPM_NV_COUNTER and TPMA_NV_ORDERLY SET.NOTE	When the loworder bits of a counter equal this value an NV write occurs on the next increment.  */
#define	TPM2_PT_MAX_COMMAND_SIZE	(TPM2_PT_FIXED + 30 )	 /* the maximum value for commandSize in a command  */
#define	TPM2_PT_MAX_RESPONSE_SIZE	(TPM2_PT_FIXED + 31 )	 /* the maximum value for responseSize in a response  */
#define	TPM2_PT_MAX_DIGEST	(TPM2_PT_FIXED + 32 )	 /* the maximum size of a digest that can be produced by the TPM  */
#define	TPM2_PT_MAX_OBJECT_CONTEXT	(TPM2_PT_FIXED + 33 )	 /* the maximum size of an object context that will be returned by TPM2_ContextSave   */
#define	TPM2_PT_MAX_SESSION_CONTEXT	(TPM2_PT_FIXED + 34 )	 /* the maximum size of a session context that will be returned by TPM2_ContextSave  */
#define	TPM2_PT_PS_FAMILY_INDICATOR	(TPM2_PT_FIXED + 35 )	 /* platformspecific family a TPM2_PS valuesee Table 25NOTE	The platformspecific values for the TPM2_PT_PS parameters are in the relevant platformspecific specification. In the reference implementation all of these values are 0.  */
#define	TPM2_PT_PS_LEVEL	(TPM2_PT_FIXED + 36 )	 /* the level of the platformspecific specification  */
#define	TPM2_PT_PS_REVISION	(TPM2_PT_FIXED + 37 )	 /* the specification Revision times 100 for the platformspecific specification  */
#define	TPM2_PT_PS_DAY_OF_YEAR	(TPM2_PT_FIXED + 38 )	 /* the platformspecific specification day of year using TCG calendar  */
#define	TPM2_PT_PS_YEAR	(TPM2_PT_FIXED + 39 )	 /* the platformspecific specification year using the CE  */
#define	TPM2_PT_SPLIT_MAX	(TPM2_PT_FIXED + 40 )	 /* the number of split signing operations supported by the TPM  */
#define	TPM2_PT_TOTAL_COMMANDS	(TPM2_PT_FIXED + 41 )	 /* total number of commands implemented in the TPM  */
#define	TPM2_PT_LIBRARY_COMMANDS	(TPM2_PT_FIXED + 42 )	 /* number of commands from the TPM library that are implemented  */
#define	TPM2_PT_VENDOR_COMMANDS	(TPM2_PT_FIXED + 43 )	 /* number of vendor commands that are implemented  */
#define	TPM2_PT_NV_BUFFER_MAX	(TPM2_PT_FIXED + 44 )	 /* the maximum data size in one NV write command  */
#define	TPM2_PT_MODES	(TPM2_PT_FIXED + 45 )	 /* a TPMA_MODES value indicating that the TPM is designed for these modes.  */
#define	TPM2_PT_VAR	(TPM2_PT_GROUP * 2 )	 /* the group of variable properties returned as TPMS_TAGGED_PROPERTYThe properties in this group change because of a Protected Capability other than a firmware update. The values are not necessarily persistent across all power transitions.  */
#define	TPM2_PT_PERMANENT	(TPM2_PT_VAR + 0 )	 /* TPMA_PERMANENT  */
#define	TPM2_PT_STARTUP_CLEAR	(TPM2_PT_VAR + 1 )	 /* TPMA_STARTUP_CLEAR  */
#define	TPM2_PT_TPM2_HR_NV_INDEX	(TPM2_PT_VAR + 2 )	 /* the number of NV Indexes currently defined  */
#define	TPM2_PT_HR_LOADED	(TPM2_PT_VAR + 3 )	 /* the number of authorization sessions currently loaded into TPM RAM  */
#define	TPM2_PT_HR_LOADED_AVAIL	(TPM2_PT_VAR + 4 )	 /* the number of additional authorization sessions of any type that could be loaded into TPM RAMThis value is an estimate. If this value is at least 1 then at least one authorization session of any type may be loaded. Any command that changes the RAM memory allocation can make this estimate invalid.NOTE	A valid implementation may return 1 even if more than one authorization session would fit into RAM.  */
#define	TPM2_PT_HR_ACTIVE	(TPM2_PT_VAR + 5 )	 /* the number of active authorization sessions currently being tracked by the TPMThis is the sum of the loaded and saved sessions.  */
#define	TPM2_PT_HR_ACTIVE_AVAIL	(TPM2_PT_VAR + 6 )	 /* the number of additional authorization sessions of any type that could be createdThis value is an estimate. If this value is at least 1 then at least one authorization session of any type may be created. Any command that changes the RAM memory allocation can make this estimate invalid.NOTE	A valid implementation may return 1 even if more than one authorization session could be created.  */
#define	TPM2_PT_TPM2_HR_TRANSIENT_AVAIL	(TPM2_PT_VAR + 7 )	 /* estimate of the number of additional transient objects that could be loaded into TPM RAMThis value is an estimate. If this value is at least 1 then at least one object of any type may be loaded. Any command that changes the memory allocation can make this estimate invalid.NOTE	A valid implementation may return 1 even if more than one transient object would fit into RAM.  */
#define	TPM2_PT_TPM2_HR_PERSISTENT	(TPM2_PT_VAR + 8 )	 /* the number of persistent objects currently loaded into TPM NV memory  */
#define	TPM2_PT_TPM2_HR_PERSISTENT_AVAIL	(TPM2_PT_VAR + 9 )	 /* the number of additional persistent objects that could be loaded into NV memoryThis value is an estimate. If this value is at least 1 then at least one object of any type may be made persistent. Any command that changes the NV memory allocation can make this estimate invalid.NOTE	A valid implementation may return 1 even if more than one persistent object would fit into NV memory.  */
#define	TPM2_PT_NV_COUNTERS	(TPM2_PT_VAR + 10 )	 /* the number of defined NV Indexes that have NV the TPM2_NT_COUNTER attribute   */
#define	TPM2_PT_NV_COUNTERS_AVAIL	(TPM2_PT_VAR + 11 )	 /* the number of additional NV Indexes that can be defined with their TPM2_NT of TPM_NV_COUNTER and the TPMA_NV_ORDERLY attribute SETThis value is an estimate. If this value is at least 1 then at least one NV Index may be created with a TPM2_NT of TPM_NV_COUNTER and the TPMA_NV_ORDERLY attributes. Any command that changes the NV memory allocation can make this estimate invalid.NOTE	A valid implementation may return 1 even if more than one NV counter could be defined.  */
#define	TPM2_PT_ALGORITHM_SET	(TPM2_PT_VAR + 12 )	 /* code that limits the algorithms that may be used with the TPM  */
#define	TPM2_PT_LOADED_CURVES	(TPM2_PT_VAR + 13 )	 /* the number of loaded ECC curves  */
#define	TPM2_PT_LOCKOUT_COUNTER	(TPM2_PT_VAR + 14 )	 /* the current value of the lockout counter failedTries  */
#define	TPM2_PT_MAX_AUTH_FAIL	(TPM2_PT_VAR + 15 )	 /* the number of authorization failures before DA lockout is invoked  */
#define	TPM2_PT_LOCKOUT_INTERVAL	(TPM2_PT_VAR + 16 )	 /* the number of seconds before the value reported by TPM2_PT_LOCKOUT_COUNTER is decremented  */
#define	TPM2_PT_LOCKOUT_RECOVERY	(TPM2_PT_VAR + 17 )	 /* the number of seconds after a lockoutAuth failure before use of lockoutAuth may be attempted again  */
#define	TPM2_PT_NV_WRITE_RECOVERY	(TPM2_PT_VAR + 18 )	 /* number of milliseconds before the TPM will accept another command that will modify NVThis value is an approximation and may go up or down over time.  */
#define	TPM2_PT_AUDIT_COUNTER_0	(TPM2_PT_VAR + 19 )	 /* the highorder 32 bits of the command audit counter  */
#define	TPM2_PT_AUDIT_COUNTER_1	(TPM2_PT_VAR + 20 )	 /* the loworder 32 bits of the command audit counter  */

/* Table 24  Definition of UINT32 TPM2_PT_PCR Constants <INOUT S> */
typedef	UINT32 TPM2_PT_PCR;
#define	TPM2_PT_TPM2_PCR_FIRST	(0x00000000 )	 /* bottom of the range of TPM2_PT_PCR properties   */
#define	TPM2_PT_PCR_SAVE	(0x00000000 )	 /* a SET bit in the TPMS_PCR_SELECT indicates that the PCR is saved and restored by TPM2_SU_STATE  */
#define	TPM2_PT_PCR_EXTEND_L0	(0x00000001 )	 /* a SET bit in the TPMS_PCR_SELECT indicates that the PCR may be extended from locality 0This property is only present if a locality other than 0 is implemented.  */
#define	TPM2_PT_PCR_RESET_L0	(0x00000002 )	 /* a SET bit in the TPMS_PCR_SELECT indicates that the PCR may be reset by TPM2_PCR_Reset from locality 0  */
#define	TPM2_PT_PCR_EXTEND_L1	(0x00000003 )	 /* a SET bit in the TPMS_PCR_SELECT indicates that the PCR may be extended from locality 1 This property is only present if locality 1 is implemented.  */
#define	TPM2_PT_PCR_RESET_L1	(0x00000004 )	 /* a SET bit in the TPMS_PCR_SELECT indicates that the PCR may be reset by TPM2_PCR_Reset from locality 1This property is only present if locality 1 is implemented.  */
#define	TPM2_PT_PCR_EXTEND_L2	(0x00000005 )	 /* a SET bit in the TPMS_PCR_SELECT indicates that the PCR may be extended from locality 2 This property is only present if localities 1 and 2 are implemented.  */
#define	TPM2_PT_PCR_RESET_L2	(0x00000006 )	 /* a SET bit in the TPMS_PCR_SELECT indicates that the PCR may be reset by TPM2_PCR_Reset from locality 2This property is only present if localities 1 and 2 are implemented.  */
#define	TPM2_PT_PCR_EXTEND_L3	(0x00000007 )	 /* a SET bit in the TPMS_PCR_SELECT indicates that the PCR may be extended from locality 3This property is only present if localities 1 2 and 3 are implemented.  */
#define	TPM2_PT_PCR_RESET_L3	(0x00000008 )	 /* a SET bit in the TPMS_PCR_SELECT indicates that the PCR may be reset by TPM2_PCR_Reset from locality 3This property is only present if localities 1 2 and 3 are implemented.  */
#define	TPM2_PT_PCR_EXTEND_L4	(0x00000009 )	 /* a SET bit in the TPMS_PCR_SELECT indicates that the PCR may be extended from locality 4This property is only present if localities 1 2 3 and 4 are implemented.  */
#define	TPM2_PT_PCR_RESET_L4	(0x0000000A )	 /* a SET bit in the TPMS_PCR_SELECT indicates that the PCR may be reset by TPM2_PCR_Reset from locality 4This property is only present if localities 1 2 3 and 4 are implemented.  */
#define	TPM2_PT_PCR_RESERVED1	(0x0000000B  0x00000010 )	 /* the values in this range are reserved They correspond to values that may be used to describe attributes associated with the extended localities 32255.synthesize additional software localities. The meaning of these properties need not be the same as the meaning for the Extend and Reset properties above.  */
#define	TPM2_PT_PCR_NO_INCREMENT	(0x00000011 )	 /* a SET bit in the TPMS_PCR_SELECT indicates that modifications to this PCR reset or Extend will not increment the pcrUpdateCounter  */
#define	TPM2_PT_PCR_DRTM_RESET	(0x00000012 )	 /* a SET bit in the TPMS_PCR_SELECT indicates that the PCR is reset by a DRTM eventThese PCR are reset to 1 on TPM2_Startup and reset to 0 on a _TPM_Hash_End event following a _TPM_Hash_Start event.  */
#define	TPM2_PT_PCR_POLICY	(0x00000013 )	 /* a SET bit in the TPMS_PCR_SELECT indicates that the PCR is controlled by policyThis property is only present if the TPM supports policy control of a PCR.  */
#define	TPM2_PT_PCR_AUTH	(0x00000014 )	 /* a SET bit in the TPMS_PCR_SELECT indicates that the PCR is controlled by an authorization valueThis property is only present if the TPM supports authorization control of a PCR.  */
#define	TPM2_PT_PCR_RESERVED2	(0x00000015 )	 /* reserved for the next 2nd TPM2_PT_PCR_POLICY set  */
#define	TPM2_PT_PCR_RESERVED3	(0x00000016 )	 /* reserved for the next 2nd TPM2_PT_PCR_AUTH set  */
#define	TPM2_PT_PCR_RESERVED4	(0x00000017  0x00000210 )	 /* reserved for the 2nd through 255th TPM2_PT_PCR_POLICY and TPM2_PT_PCR_AUTH values  */
#define	TPM2_PT_PCR_RESERVED5	(0x00000211 )	 /* reserved to the 256th and highest allowed TPM2_PT_PCR_POLICY set  */
#define	TPM2_PT_PCR_RESERVED6	(0x00000212 )	 /* reserved to the 256th and highest allowed TPM2_PT_PCR_AUTH set  */
#define	TPM2_PT_PCR_RESERVED7	(0x00000213 )	 /* new PCR property values may be assigned starting with this value  */
#define	TPM2_PT_TPM2_PCR_LAST	(0x00000014 )	 /* top of the range of TPM2_PT_PCR properties of the implementationIf the TPM receives a request for a PCR property with a value larger than this the TPM will return a zero length list and set the moreData parameter to NO.NOTE	This is an implementationspecific value. The value shown reflects the reference code implementation.  */

/* Table 25  Definition of UINT32 TPM2_PS Constants <OUT> */
typedef	UINT32 TPM2_PS;
#define	TPM2_PS_MAIN	(0x00000000 )	 /* not platform specific   */
#define	TPM2_PS_PC	(0x00000001 )	 /* PC Client  */
#define	TPM2_PS_PDA	(0x00000002 )	 /* PDA includes all mobile devices that are not specifically cell phones  */
#define	TPM2_PS_CELL_PHONE	(0x00000003 )	 /* Cell Phone   */
#define	TPM2_PS_SERVER	(0x00000004 )	 /* Server WG  */
#define	TPM2_PS_PERIPHERAL	(0x00000005 )	 /* Peripheral WG  */
#define	TPM2_PS_TSS	(0x00000006 )	 /* TSS WG  */
#define	TPM2_PS_STORAGE	(0x00000007 )	 /* Storage WG  */
#define	TPM2_PS_AUTHENTICATION	(0x00000008 )	 /* Authentication WG  */
#define	TPM2_PS_EMBEDDED	(0x00000009 )	 /* Embedded WG  */
#define	TPM2_PS_HARDCOPY	(0x0000000A )	 /* Hardcopy WG  */
#define	TPM2_PS_INFRASTRUCTURE	(0x0000000B )	 /* Infrastructure WG  */
#define	TPM2_PS_VIRTUALIZATION	(0x0000000C )	 /* Virtualization WG  */
#define	TPM2_PS_TNC	(0x0000000D )	 /* Trusted Network Connect WG  */
#define	TPM2_PS_MULTI_TENANT	(0x0000000E )	 /* Multitenant WG  */
#define	TPM2_PS_TC	(0x0000000F )	 /* Technical Committee  */

/* Table 26  Definition of Types for Handles */
typedef	UINT32	TPM2_HANDLE;	 /*   */

/* Table 27  Definition of UINT8 TPM2_HT Constants <S> */
typedef	UINT8 TPM2_HT;
#define	TPM2_HT_PCR	(0x00 )	 /* PCR  consecutive numbers starting at 0 that reference the PCR registersA platformspecific specification will set the minimum number of PCR and an implementation may have more.   */
#define	TPM2_HT_NV_INDEX	(0x01 )	 /* NV Index  assigned by the caller  */
#define	TPM2_HT_HMAC_SESSION	(0x02 )	 /* HMAC Authorization Session  assigned by the TPM when the session is created  */
#define	TPM2_HT_LOADED_SESSION	(0x02 )	 /* Loaded Authorization Session  used only in the context of TPM2_GetCapabilityThis type references both loaded HMAC and loaded policy authorization sessions.   */
#define	TPM2_HT_POLICY_SESSION	(0x03 )	 /* Policy Authorization Session  assigned by the TPM when the session is created  */
#define	TPM2_HT_SAVED_SESSION	(0x03 )	 /* Saved Authorization Session  used only in the context of TPM2_GetCapabilityThis type references saved authorization session contexts for which the TPM is maintaining tracking information.  */
#define	TPM2_HT_PERMANENT	(0x40 )	 /* Permanent Values  assigned by this specification in Table 28  */
#define	TPM2_HT_TRANSIENT	(0x80 )	 /* Transient Objects  assigned by the TPM when an object is loaded into transientobject memory or when a persistent object is converted to a transient object  */
#define	TPM2_HT_PERSISTENT	(0x81 )	 /* Persistent Objects  assigned by the TPM when a loaded transient object is made persistent  */

/* Table 28  Definition of TPM2_HANDLE TPM2_RH Constants <S> */
typedef	TPM2_HANDLE TPM2_RH;
#define	TPM2_RH_FIRST	(0x40000000 )	 /* R  */
#define	TPM2_RH_SRK	(0x40000000 )	 /* R  */
#define	TPM2_RH_OWNER	(0x40000001 )	 /* K A P  */
#define	TPM2_RH_REVOKE	(0x40000002 )	 /* R  */
#define	TPM2_RH_TRANSPORT	(0x40000003 )	 /* R  */
#define	TPM2_RH_OPERATOR	(0x40000004 )	 /* R  */
#define	TPM2_RH_ADMIN	(0x40000005 )	 /* R  */
#define	TPM2_RH_EK	(0x40000006 )	 /* R  */
#define	TPM2_RH_NULL	(0x40000007 )	 /* K A P  */
#define	TPM2_RH_UNASSIGNED	(0x40000008 )	 /* R  */
#define	TPM2_RS_PW	(0x40000009 )	 /* S  */
#define	TPM2_RH_LOCKOUT	(0x4000000A )	 /* A  */
#define	TPM2_RH_ENDORSEMENT	(0x4000000B )	 /* K A P  */
#define	TPM2_RH_PLATFORM	(0x4000000C )	 /* K A P  */
#define	TPM2_RH_PLATFORM_NV	(0x4000000D )	 /* C  */
#define	TPM2_RH_AUTH_00	(0x40000010 )	 /* A  */
#define	TPM2_RH_AUTH_FF	(0x4000010F )	 /* A  */
#define	TPM2_RH_LAST	(0x4000010F )	 /* R  */

/* Table 29  Definition of TPM2_HANDLE TPM2_HC Constants <S> */
typedef	TPM2_HANDLE TPM2_HC;
#define	TPM2_HR_HANDLE_MASK	(0x00FFFFFF )	 /* to mask off the HR  */
#define	TPM2_HR_RANGE_MASK	(0xFF000000 )	 /* to mask off the variable part  */
#define	TPM2_HR_SHIFT	(24 )	 /*   */
#define	TPM2_HR_PCR	(TPM2_HT_PCR << TPM2_HR_SHIFT )	 /*   */
#define	TPM2_HR_HMAC_SESSION	(TPM2_HT_HMAC_SESSION << TPM2_HR_SHIFT )	 /*   */
#define	TPM2_HR_POLICY_SESSION	(TPM2_HT_POLICY_SESSION << TPM2_HR_SHIFT )	 /*   */
#define	TPM2_HR_TRANSIENT	(TPM2_HT_TRANSIENT << TPM2_HR_SHIFT )	 /*   */
#define	TPM2_HR_PERSISTENT	(TPM2_HT_PERSISTENT << TPM2_HR_SHIFT )	 /*   */
#define	TPM2_HR_NV_INDEX	(TPM2_HT_NV_INDEX << TPM2_HR_SHIFT )	 /*   */
#define	TPM2_HR_PERMANENT	(TPM2_HT_PERMANENT << TPM2_HR_SHIFT )	 /*   */
#define	TPM2_PCR_FIRST	(TPM2_HR_PCR + 0 )	 /* first PCR  */
#define	TPM2_PCR_LAST	(TPM2_PCR_FIRST + TPM2_MAX_PCRS - 1 )	 /* last PCR  */
#define	TPM2_HMAC_SESSION_FIRST	(TPM2_HR_HMAC_SESSION + 0 )	 /* first HMAC session  */
#define	TPM2_HMAC_SESSION_LAST	(TPM2_HMAC_SESSION_FIRST + 0x00fffffe )	 /* last HMAC session  */
#define	TPM2_LOADED_SESSION_FIRST	(TPM2_HMAC_SESSION_FIRST )	 /* used in GetCapability  */
#define	TPM2_LOADED_SESSION_LAST	(TPM2_HMAC_SESSION_LAST )	 /* used in GetCapability  */
#define	TPM2_POLICY_SESSION_FIRST	(TPM2_HR_POLICY_SESSION + 0 )	 /* first policy session  */
#define	TPM2_POLICY_SESSION_LAST	(TPM2_POLICY_SESSION_FIRST + 0x00fffffe )	 /* last policy session   */
#define	TPM2_TRANSIENT_FIRST	(TPM2_HR_TRANSIENT + 0 )	 /* first transient object  */
#define	TPM2_ACTIVE_SESSION_FIRST	(TPM2_POLICY_SESSION_FIRST )	 /* used in GetCapability  */
#define	TPM2_ACTIVE_SESSION_LAST	(TPM2_POLICY_SESSION_LAST )	 /* used in GetCapability  */
#define	TPM2_TRANSIENT_LAST	(TPM2_TRANSIENT_FIRST + 0x00fffffe )	 /* last transient object  */
#define	TPM2_PERSISTENT_FIRST	(TPM2_HR_PERSISTENT + 0 )	 /* first persistent object  */
#define	TPM2_PERSISTENT_LAST	(TPM2_PERSISTENT_FIRST + 0x00FFFFFF )	 /* last persistent object  */
#define	TPM2_PLATFORM_PERSISTENT	(TPM2_PERSISTENT_FIRST + 0x00800000 )	 /* first platform persistent object  */
#define	TPM2_NV_INDEX_FIRST	(TPM2_HR_NV_INDEX + 0 )	 /* first allowed NV Index  */
#define	TPM2_NV_INDEX_LAST	(TPM2_NV_INDEX_FIRST + 0x00FFFFFF )	 /* last allowed NV Index  */
#define	TPM2_PERMANENT_FIRST	(TPM2_RH_FIRST )	 /*   */
#define	TPM2_PERMANENT_LAST	(TPM2_RH_LAST )	 /*   */

/* Table 30  Definition of UINT32 TPMA_ALGORITHM Bits */
#if defined TPM_BITFIELD_LE

typedef union {
	struct {
	unsigned int asymmetric : 1;	/* SET 1 an asymmetric algorithm with public and private portionsCLEAR 0 not an asymmetric algorithm  */
	unsigned int symmetric : 1;	/* SET 1 a symmetric block cipherCLEAR 0 not a symmetric block cipher  */
	unsigned int hash : 1;	/* SET 1 a hash algorithmCLEAR 0 not a hash algorithm  */
	unsigned int object : 1;	/* SET 1 an algorithm that may be used as an object typeCLEAR 0 an algorithm that is not used as an object type  */
	unsigned int reserved1 : 4;	/*   */
	unsigned int signing : 1;	/* SET 1 a signing algorithm. The setting of asymmetric symmetric and hash will indicate the type of signing algorithm.CLEAR 0 not a signing algorithm  */
	unsigned int encrypting : 1;	/* SET 1 an encryptiondecryption algorithm. The setting of asymmetric symmetric and hash will indicate the type of encryptiondecryption algorithm.CLEAR 0 not an encryptiondecryption algorithm   */
	unsigned int method : 1;	/* SET 1 a method such as a key derivative function KDFCLEAR 0 not a method  */
	unsigned int reserved2 : 21;	/*   */
	};
	UINT32 val;
} TPMA_ALGORITHM;

#elif defined TPM_BITFIELD_BE

typedef union {
	struct {
	unsigned int reserved1 : 21;	/*   */
	unsigned int method : 1;	/* SET 1 a method such as a key derivative function KDFCLEAR 0 not a method  */
	unsigned int encrypting : 1;	/* SET 1 an encryptiondecryption algorithm. The setting of asymmetric symmetric and hash will indicate the type of encryptiondecryption algorithm.CLEAR 0 not an encryptiondecryption algorithm   */
	unsigned int signing : 1;	/* SET 1 a signing algorithm. The setting of asymmetric symmetric and hash will indicate the type of signing algorithm.CLEAR 0 not a signing algorithm  */
	unsigned int reserved2 : 4;	/*   */
	unsigned int object : 1;	/* SET 1 an algorithm that may be used as an object typeCLEAR 0 an algorithm that is not used as an object type  */
	unsigned int hash : 1;	/* SET 1 a hash algorithmCLEAR 0 not a hash algorithm  */
	unsigned int symmetric : 1;	/* SET 1 a symmetric block cipherCLEAR 0 not a symmetric block cipher  */
	unsigned int asymmetric : 1;	/* SET 1 an asymmetric algorithm with public and private portionsCLEAR 0 not an asymmetric algorithm  */
	};
	UINT32 val;
} TPMA_ALGORITHM;

#else

typedef uint32_t	TPMA_ALGORITHM;

#endif

#define TPMA_ALGORITHM_ASYMMETRIC	0x00000001
#define TPMA_ALGORITHM_SYMMETRIC	0x00000002
#define TPMA_ALGORITHM_HASH	0x00000004
#define TPMA_ALGORITHM_OBJECT	0x00000008
#define TPMA_ALGORITHM_RESERVED1	0x000000F0
#define TPMA_ALGORITHM_SIGNING	0x00000100
#define TPMA_ALGORITHM_ENCRYPTING	0x00000200
#define TPMA_ALGORITHM_METHOD	0x00000400
#define TPMA_ALGORITHM_RESERVED2	0xFFFFF800


/* Table 31  Definition of UINT32 TPMA_OBJECT Bits */
#if defined TPM_BITFIELD_LE

typedef union {
	struct {
	unsigned int reserved1 : 1;	/* shall be zero  */
	unsigned int fixedTPM : 1;	/* SET 1 The hierarchy of the object as indicated by its Qualified Name may not change.CLEAR 0 The hierarchy of the object may change as a result of this object or an ancestor key being duplicated for use in another hierarchy.  */
	unsigned int stClear : 1;	/* SET 1 Previously saved contexts of this object may not be loaded after StartupCLEAR.CLEAR 0 Saved contexts of this object may be used after a ShutdownSTATE and subsequent Startup.  */
	unsigned int reserved2 : 1;	/* shall be zero  */
	unsigned int fixedParent : 1;	/* SET 1 The parent of the object may not change.CLEAR 0 The parent of the object may change as the result of a TPM2_Duplicate of the object.  */
	unsigned int sensitiveDataOrigin : 1;	/* SET 1 Indicates that when the object was created with TPM2_Create or TPM2_CreatePrimary the TPM generated all of the sensitive data other than the authValue.CLEAR 0 A portion of the sensitive data other than the authValue was provided by the caller.  */
	unsigned int userWithAuth : 1;	/* SET 1 Approval of USER role actions with this object may be with an HMAC session or with a password using the authValue of the object or a policy session.CLEAR 0 Approval of USER role actions with this object may only be done with a policy session.  */
	unsigned int adminWithPolicy : 1;	/* SET 1 Approval of ADMIN role actions with this object may only be done with a policy session.CLEAR 0 Approval of ADMIN role actions with this object may be with an HMAC session or with a password using the authValue of the object or a policy session.  */
	unsigned int reserved3 : 2;	/* shall be zero  */
	unsigned int noDA : 1;	/* SET 1 The object is not subject to dictionary attack protections.CLEAR 0 The object is subject to dictionary attack protections.  */
	unsigned int encryptedDuplication : 1;	/* SET 1 If the object is duplicated then symmetricAlg shall not be TPM2_ALG_NULL and newParentHandle shall not be TPM2_RH_NULL.CLEAR 0 The object may be duplicated without an inner wrapper on the private portion of the object and the new parent may be TPM2_RH_NULL.  */
	unsigned int reserved4 : 4;	/* shall be zero  */
	unsigned int restricted : 1;	/* SET 1 Key usage is restricted to manipulate structures of known format the parent of this key shall have restricted SET.CLEAR 0 Key usage is not restricted to use on special formats.  */
	unsigned int decrypt : 1;	/* SET 1 The private portion of the key may be used to decrypt.CLEAR 0 The private portion of the key may not be used to decrypt.  */
	unsigned int sign : 1;	/* SET 1 For a symmetric cipher object the private portion of the key may be used to encrypt.  For other objects the private portion of the key may be used to sign.CLEAR 0 The private portion of the key may not be used to sign or encrypt.  */
	unsigned int reserved5 : 13;	/* shall be zero  */
	};
	UINT32 val;
} TPMA_OBJECT;

#elif defined TPM_BITFIELD_BE

typedef union {
	struct {
	unsigned int reserved1 : 13;	/* shall be zero  */
	unsigned int sign : 1;	/* SET 1 For a symmetric cipher object the private portion of the key may be used to encrypt.  For other objects the private portion of the key may be used to sign.CLEAR 0 The private portion of the key may not be used to sign or encrypt.  */
	unsigned int decrypt : 1;	/* SET 1 The private portion of the key may be used to decrypt.CLEAR 0 The private portion of the key may not be used to decrypt.  */
	unsigned int restricted : 1;	/* SET 1 Key usage is restricted to manipulate structures of known format the parent of this key shall have restricted SET.CLEAR 0 Key usage is not restricted to use on special formats.  */
	unsigned int reserved2 : 4;	/* shall be zero  */
	unsigned int encryptedDuplication : 1;	/* SET 1 If the object is duplicated then symmetricAlg shall not be TPM2_ALG_NULL and newParentHandle shall not be TPM2_RH_NULL.CLEAR 0 The object may be duplicated without an inner wrapper on the private portion of the object and the new parent may be TPM2_RH_NULL.  */
	unsigned int noDA : 1;	/* SET 1 The object is not subject to dictionary attack protections.CLEAR 0 The object is subject to dictionary attack protections.  */
	unsigned int reserved3 : 2;	/* shall be zero  */
	unsigned int adminWithPolicy : 1;	/* SET 1 Approval of ADMIN role actions with this object may only be done with a policy session.CLEAR 0 Approval of ADMIN role actions with this object may be with an HMAC session or with a password using the authValue of the object or a policy session.  */
	unsigned int userWithAuth : 1;	/* SET 1 Approval of USER role actions with this object may be with an HMAC session or with a password using the authValue of the object or a policy session.CLEAR 0 Approval of USER role actions with this object may only be done with a policy session.  */
	unsigned int sensitiveDataOrigin : 1;	/* SET 1 Indicates that when the object was created with TPM2_Create or TPM2_CreatePrimary the TPM generated all of the sensitive data other than the authValue.CLEAR 0 A portion of the sensitive data other than the authValue was provided by the caller.  */
	unsigned int fixedParent : 1;	/* SET 1 The parent of the object may not change.CLEAR 0 The parent of the object may change as the result of a TPM2_Duplicate of the object.  */
	unsigned int reserved4 : 1;	/* shall be zero  */
	unsigned int stClear : 1;	/* SET 1 Previously saved contexts of this object may not be loaded after StartupCLEAR.CLEAR 0 Saved contexts of this object may be used after a ShutdownSTATE and subsequent Startup.  */
	unsigned int fixedTPM : 1;	/* SET 1 The hierarchy of the object as indicated by its Qualified Name may not change.CLEAR 0 The hierarchy of the object may change as a result of this object or an ancestor key being duplicated for use in another hierarchy.  */
	unsigned int reserved5 : 1;	/* shall be zero  */
	};
	UINT32 val;
} TPMA_OBJECT;

#else

typedef uint32_t	TPMA_OBJECT;

#endif

#define TPMA_OBJECT_RESERVED1	0x00000001
#define TPMA_OBJECT_FIXEDTPM	0x00000002
#define TPMA_OBJECT_STCLEAR	0x00000004
#define TPMA_OBJECT_RESERVED2	0x00000008
#define TPMA_OBJECT_FIXEDPARENT	0x00000010
#define TPMA_OBJECT_SENSITIVEDATAORIGIN	0x00000020
#define TPMA_OBJECT_USERWITHAUTH	0x00000040
#define TPMA_OBJECT_ADMINWITHPOLICY	0x00000080
#define TPMA_OBJECT_RESERVED3	0x00000300
#define TPMA_OBJECT_NODA	0x00000400
#define TPMA_OBJECT_ENCRYPTEDDUPLICATION	0x00000800
#define TPMA_OBJECT_RESERVED4	0x0000F000
#define TPMA_OBJECT_RESTRICTED	0x00010000
#define TPMA_OBJECT_DECRYPT	0x00020000
#define TPMA_OBJECT_SIGN	0x00040000
#define TPMA_OBJECT_SIGN_ENCRYPT	0x00040000
#define TPMA_OBJECT_RESERVED5	0xFFF80000


/* Table 32  Definition of UINT8 TPMA_SESSION Bits <INOUT> */
#if defined TPM_BITFIELD_LE

typedef union {
	struct {
	unsigned char continueSession : 1;	/* SET 1 In a command this setting indicates that the session is to remain active after successful completion of the command. In a response it indicates that the session is still active. If SET in the command this attribute shall be SET in the response.CLEAR 0 In a command this setting indicates that the TPM should close the session and flush any related context when the command completes successfully. In a response it indicates that the session is closed and the context is no longer active.This attribute has no meaning for a password authorization and the TPM will allow any setting of the attribute in the command and SET the attribute in the response.This attribute will only be CLEAR in one response for a logical session. If the attribute is CLEAR the context associated with the session is no longer in use and the space is available. A session created after another session is ended may have the same handle but logically is not the same session.This attribute has no effect if the command does not complete successfully.  */
	unsigned char auditExclusive : 1;	/* SET 1 In a command this setting indicates that the command should only be executed if the session is exclusive at the start of the command. In a response it indicates that the session is exclusive. This setting is only allowed if the audit attribute is SET TPM2_RC_ATTRIBUTES.CLEAR 0 In a command indicates that the session need not be exclusive at the start of the command.  In a response indicates that the session is not exclusive.In this revision if audit is CLEAR auditExclusive must be CLEAR in the command and will be CLEAR in the response.  In a future revision this bit may have a different meaning if audit is CLEAR.See Exclusive Audit Session clause in TPM 2.0 Part 1.  */
	unsigned char auditReset : 1;	/* SET 1 In a command this setting indicates that the audit digest of the session should be initialized and the exclusive status of the session SET. This setting is only allowed if the audit attribute is SET TPM2_RC_ATTRIBUTES.CLEAR 0 In a command indicates that the audit digest should not be initialized.This bit is always CLEAR in a response.In this revision if audit is CLEAR auditReset must be clear in the command and will be CLEAR in the response.  In a future revision this bit may have a different meaning if audit is CLEAR.  */
	unsigned char reserved1 : 2;	/* shall be CLEAR  */
	unsigned char decrypt : 1;	/* SET 1 In a command this setting indicates that the first parameter in the command is symmetrically encrypted using the parameter encryption scheme described in TPM 2.0 Part 1. The TPM will decrypt the parameter after performing any HMAC computations and before unmarshaling the parameter. In a response the attribute is copied from the request but has no effect on the response.CLEAR 0 Session not used for encryption.For a password authorization this attribute will be CLEAR in both the command and response.This attribute may only be SET in one session per command.This attribute may be SET in a session that is not associated with a command handle. Such a session is provided for purposes of encrypting a parameter and not for authorization.This attribute may be SET in combination with any other session attributes.This attribute may only be SET if the first parameter of the command is a sized buffer TPM2B_.  */
	unsigned char encrypt : 1;	/* SET 1 In a command this setting indicates that the TPM should use this session to encrypt the first parameter in the response. In a response it indicates that the attribute was set in the command and that the TPM used the session to encrypt the first parameter in the response using the parameter encryption scheme described in TPM 2.0 Part 1.CLEAR 0 Session not used for encryption.For a password authorization this attribute will be CLEAR in both the command and response.This attribute may only be SET in one session per command.This attribute may be SET in a session that is not associated with a command handle. Such a session is provided for purposes of encrypting a parameter and not for authorization.This attribute may only be SET if the first parameter of a response is a sized buffer TPM2B_.  */
	unsigned char audit : 1;	/* SET 1 In a command or response this setting indicates that the session is for audit and that auditExclusive and auditReset have meaning. This session may also be used for authorization encryption or decryption. The encrypted and encrypt fields may be SET or CLEAR.CLEAR 0 Session is not used for audit.This attribute may only be SET in one session per command or response. If SET in the command then this attribute will be SET in the response.  */
	};
	UINT8 val;
} TPMA_SESSION;

#elif defined TPM_BITFIELD_BE

typedef union {
	struct {
	unsigned char audit : 1;	/* SET 1 In a command or response this setting indicates that the session is for audit and that auditExclusive and auditReset have meaning. This session may also be used for authorization encryption or decryption. The encrypted and encrypt fields may be SET or CLEAR.CLEAR 0 Session is not used for audit.This attribute may only be SET in one session per command or response. If SET in the command then this attribute will be SET in the response.  */
	unsigned char encrypt : 1;	/* SET 1 In a command this setting indicates that the TPM should use this session to encrypt the first parameter in the response. In a response it indicates that the attribute was set in the command and that the TPM used the session to encrypt the first parameter in the response using the parameter encryption scheme described in TPM 2.0 Part 1.CLEAR 0 Session not used for encryption.For a password authorization this attribute will be CLEAR in both the command and response.This attribute may only be SET in one session per command.This attribute may be SET in a session that is not associated with a command handle. Such a session is provided for purposes of encrypting a parameter and not for authorization.This attribute may only be SET if the first parameter of a response is a sized buffer TPM2B_.  */
	unsigned char decrypt : 1;	/* SET 1 In a command this setting indicates that the first parameter in the command is symmetrically encrypted using the parameter encryption scheme described in TPM 2.0 Part 1. The TPM will decrypt the parameter after performing any HMAC computations and before unmarshaling the parameter. In a response the attribute is copied from the request but has no effect on the response.CLEAR 0 Session not used for encryption.For a password authorization this attribute will be CLEAR in both the command and response.This attribute may only be SET in one session per command.This attribute may be SET in a session that is not associated with a command handle. Such a session is provided for purposes of encrypting a parameter and not for authorization.This attribute may be SET in combination with any other session attributes.This attribute may only be SET if the first parameter of the command is a sized buffer TPM2B_.  */
	unsigned char reserved1 : 2;	/* shall be CLEAR  */
	unsigned char auditReset : 1;	/* SET 1 In a command this setting indicates that the audit digest of the session should be initialized and the exclusive status of the session SET. This setting is only allowed if the audit attribute is SET TPM2_RC_ATTRIBUTES.CLEAR 0 In a command indicates that the audit digest should not be initialized.This bit is always CLEAR in a response.In this revision if audit is CLEAR auditReset must be clear in the command and will be CLEAR in the response.  In a future revision this bit may have a different meaning if audit is CLEAR.  */
	unsigned char auditExclusive : 1;	/* SET 1 In a command this setting indicates that the command should only be executed if the session is exclusive at the start of the command. In a response it indicates that the session is exclusive. This setting is only allowed if the audit attribute is SET TPM2_RC_ATTRIBUTES.CLEAR 0 In a command indicates that the session need not be exclusive at the start of the command.  In a response indicates that the session is not exclusive.In this revision if audit is CLEAR auditExclusive must be CLEAR in the command and will be CLEAR in the response.  In a future revision this bit may have a different meaning if audit is CLEAR.See Exclusive Audit Session clause in TPM 2.0 Part 1.  */
	unsigned char continueSession : 1;	/* SET 1 In a command this setting indicates that the session is to remain active after successful completion of the command. In a response it indicates that the session is still active. If SET in the command this attribute shall be SET in the response.CLEAR 0 In a command this setting indicates that the TPM should close the session and flush any related context when the command completes successfully. In a response it indicates that the session is closed and the context is no longer active.This attribute has no meaning for a password authorization and the TPM will allow any setting of the attribute in the command and SET the attribute in the response.This attribute will only be CLEAR in one response for a logical session. If the attribute is CLEAR the context associated with the session is no longer in use and the space is available. A session created after another session is ended may have the same handle but logically is not the same session.This attribute has no effect if the command does not complete successfully.  */
	};
	UINT8 val;
} TPMA_SESSION;

#else

typedef UINT8 TPMA_SESSION;

#endif

#define TPMA_SESSION_CONTINUESESSION	0x00000001
#define TPMA_SESSION_AUDITEXCLUSIVE	0x00000002
#define TPMA_SESSION_AUDITRESET	0x00000004
#define TPMA_SESSION_RESERVED1	0x00000018
#define TPMA_SESSION_DECRYPT	0x00000020
#define TPMA_SESSION_ENCRYPT	0x00000040
#define TPMA_SESSION_AUDIT	0x00000080


/* Table 33  Definition of UINT8 TPMA_LOCALITY Bits <INOUT> */
#if defined TPM_BITFIELD_LE

typedef union {
	struct {
	unsigned char TPM2_LOC_ZERO : 1;	/*   */
	unsigned char TPM2_LOC_ONE : 1;	/*   */
	unsigned char TPM2_LOC_TWO : 1;	/*   */
	unsigned char TPM2_LOC_THREE : 1;	/*   */
	unsigned char TPM2_LOC_FOUR : 1;	/*   */
	unsigned char Extended : 3;	/* If any of these bits is set an extended locality is indicated  */
	};
	UINT8 val;
} TPMA_LOCALITY;

#elif defined TPM_BITFIELD_BE

typedef union {
	struct {
	unsigned char Extended : 3;	/* If any of these bits is set an extended locality is indicated  */
	unsigned char TPM2_LOC_FOUR : 1;	/*   */
	unsigned char TPM2_LOC_THREE : 1;	/*   */
	unsigned char TPM2_LOC_TWO : 1;	/*   */
	unsigned char TPM2_LOC_ONE : 1;	/*   */
	unsigned char TPM2_LOC_ZERO : 1;	/*   */
	};
	UINT8 val;
} TPMA_LOCALITY;

#else

typedef UINT8 TPMA_LOCALITY;

#endif

#define TPMA_LOCALITY_TPM2_LOC_ZERO	0x00000001
#define TPMA_LOCALITY_TPM2_LOC_ONE	0x00000002
#define TPMA_LOCALITY_TPM2_LOC_TWO	0x00000004
#define TPMA_LOCALITY_TPM2_LOC_THREE	0x00000008
#define TPMA_LOCALITY_TPM2_LOC_FOUR	0x00000010
#define TPMA_LOCALITY_EXTENDED	0x000000E0


/* Table 34  Definition of UINT32 TPMA_PERMANENT Bits <OUT> */
#if defined TPM_BITFIELD_LE

typedef union {
	struct {
	unsigned int ownerAuthSet : 1;	/* SET 1 TPM2_HierarchyChangeAuth with ownerAuth has been executed since the last TPM2_Clear.CLEAR 0 ownerAuth has not been changed since TPM2_Clear.  */
	unsigned int endorsementAuthSet : 1;	/* SET 1 TPM2_HierarchyChangeAuth with endorsementAuth has been executed since the last TPM2_Clear.CLEAR 0 endorsementAuth has not been changed since TPM2_Clear.  */
	unsigned int lockoutAuthSet : 1;	/* SET 1 TPM2_HierarchyChangeAuth with lockoutAuth has been executed since the last TPM2_Clear.CLEAR 0 lockoutAuth has not been changed since TPM2_Clear.  */
	unsigned int reserved1 : 5;	/*   */
	unsigned int disableClear : 1;	/* SET 1 TPM2_Clear is disabled.CLEAR 0 TPM2_Clear is enabled.NOTE	See TPM2_ClearControl in TPM 2.0 Part 3 for details on changing this attribute.  */
	unsigned int inLockout : 1;	/* SET 1 The TPM is in lockout and commands that require authorization with other than Platform Authorization or Lockout Authorization will not succeed.  */
	unsigned int tpmGeneratedEPS : 1;	/* SET 1 The EPS was created by the TPM.CLEAR 0 The EPS was created outside of the TPM using a manufacturerspecific process.  */
	unsigned int reserved2 : 21;	/*   */
	};
	UINT32 val;
} TPMA_PERMANENT;

#elif defined TPM_BITFIELD_BE

typedef union {
	struct {
	unsigned int reserved1 : 21;	/*   */
	unsigned int tpmGeneratedEPS : 1;	/* SET 1 The EPS was created by the TPM.CLEAR 0 The EPS was created outside of the TPM using a manufacturerspecific process.  */
	unsigned int inLockout : 1;	/* SET 1 The TPM is in lockout and commands that require authorization with other than Platform Authorization or Lockout Authorization will not succeed.  */
	unsigned int disableClear : 1;	/* SET 1 TPM2_Clear is disabled.CLEAR 0 TPM2_Clear is enabled.NOTE	See TPM2_ClearControl in TPM 2.0 Part 3 for details on changing this attribute.  */
	unsigned int reserved2 : 5;	/*   */
	unsigned int lockoutAuthSet : 1;	/* SET 1 TPM2_HierarchyChangeAuth with lockoutAuth has been executed since the last TPM2_Clear.CLEAR 0 lockoutAuth has not been changed since TPM2_Clear.  */
	unsigned int endorsementAuthSet : 1;	/* SET 1 TPM2_HierarchyChangeAuth with endorsementAuth has been executed since the last TPM2_Clear.CLEAR 0 endorsementAuth has not been changed since TPM2_Clear.  */
	unsigned int ownerAuthSet : 1;	/* SET 1 TPM2_HierarchyChangeAuth with ownerAuth has been executed since the last TPM2_Clear.CLEAR 0 ownerAuth has not been changed since TPM2_Clear.  */
	};
	UINT32 val;
} TPMA_PERMANENT;

#else

typedef uint32_t	TPMA_PERMANENT;

#endif

#define TPMA_PERMANENT_OWNERAUTHSET	0x00000001
#define TPMA_PERMANENT_ENDORSEMENTAUTHSET	0x00000002
#define TPMA_PERMANENT_LOCKOUTAUTHSET	0x00000004
#define TPMA_PERMANENT_RESERVED1	0x000000F8
#define TPMA_PERMANENT_DISABLECLEAR	0x00000100
#define TPMA_PERMANENT_INLOCKOUT	0x00000200
#define TPMA_PERMANENT_TPMGENERATEDEPS	0x00000400
#define TPMA_PERMANENT_RESERVED2	0xFFFFF800


/* Table 35  Definition of UINT32 TPMA_STARTUP_CLEAR Bits <OUT> */
#if defined TPM_BITFIELD_LE

typedef union {
	struct {
	unsigned int phEnable : 1;	/* SET 1 The platform hierarchy is enabled and platformAuth or platformPolicy may be used for authorization.CLEAR 0 platformAuth and platformPolicy may not be used for authorizations and objects in the platform hierarchy including persistent objects cannot be used.NOTE	See TPM2_HierarchyControl in TPM 2.0 Part 3 for details on changing this attribute.  */
	unsigned int shEnable : 1;	/* SET 1 The Storage hierarchy is enabled and ownerAuth or ownerPolicy may be used for authorization. NV indices defined using owner authorization are accessible.CLEAR 0 ownerAuth and ownerPolicy may not be used for authorizations and objects in the Storage hierarchy persistent objects and NV indices defined using owner authorization cannot be used.NOTE	See TPM2_HierarchyControl in TPM 2.0 Part 3 for details on changing this attribute.  */
	unsigned int ehEnable : 1;	/* SET 1 The EPS hierarchy is enabled and Endorsement Authorization may be used to authorize commands.CLEAR 0 Endorsement Authorization may not be used for authorizations and objects in the endorsement hierarchy including persistent objects cannot be used.NOTE	See TPM2_HierarchyControl in TPM 2.0 Part 3 for details on changing this attribute.  */
	unsigned int phEnableNV : 1;	/* SET 1 NV indices that have TPMA_PLATFORM_CREATE SET may be read or written. The platform can create define and undefine indices.CLEAR 0 NV indices that have TPMA_PLATFORM_CREATE SET may not be read or written TPM2_RC_HANDLE. The platform cannot  define TPM2_RC_HIERARCHY or undefined TPM2_RC_HANDLE indices.NOTE	See TPM2_HierarchyControl in TPM 2.0 Part 3 for details on changing this attribute.NOTE read refers to these commands TPM2_NV_Read TPM2_NV_ReadPublic TPM_NV_Certify TPM2_PolicyNVwrite refers to these commands TPM2_NV_Write TPM2_NV_Increment TPM2_NV_Extend TPM2_NV_SetBitsNOTE The TPM must query the index TPMA_PLATFORM_CREATE attribute to determine whether phEnableNV is applicable. Since the TPM will return TPM2_RC_HANDLE if the index does not exist it also returns this error code if the index is disabled. Otherwise the TPM would leak the existence of an index even when disabled.  */
	unsigned int reserved1 : 27;	/* shall be zero  */
	unsigned int orderly : 1;	/* SET 1 The TPM received a TPM2_Shutdown and a matching TPM2_Startup.CLEAR 0 TPM2_StartupTPM2_SU_CLEAR was not preceded by a TPM2_Shutdown of any type.NOTE 	A shutdown is orderly if the TPM receives a TPM2_Shutdown of any type followed by a TPM2_Startup of any type. However the TPM will return an error if TPM2_StartupTPM2_SU_STATE was not preceded by TPM2_State_SaveTPM2_SU_STATE.  */
	};
	UINT32 val;
} TPMA_STARTUP_CLEAR;

#elif defined TPM_BITFIELD_BE

typedef union {
	struct {
	unsigned int orderly : 1;	/* SET 1 The TPM received a TPM2_Shutdown and a matching TPM2_Startup.CLEAR 0 TPM2_StartupTPM2_SU_CLEAR was not preceded by a TPM2_Shutdown of any type.NOTE 	A shutdown is orderly if the TPM receives a TPM2_Shutdown of any type followed by a TPM2_Startup of any type. However the TPM will return an error if TPM2_StartupTPM2_SU_STATE was not preceded by TPM2_State_SaveTPM2_SU_STATE.  */
	unsigned int reserved1 : 27;	/* shall be zero  */
	unsigned int phEnableNV : 1;	/* SET 1 NV indices that have TPMA_PLATFORM_CREATE SET may be read or written. The platform can create define and undefine indices.CLEAR 0 NV indices that have TPMA_PLATFORM_CREATE SET may not be read or written TPM2_RC_HANDLE. The platform cannot  define TPM2_RC_HIERARCHY or undefined TPM2_RC_HANDLE indices.NOTE	See TPM2_HierarchyControl in TPM 2.0 Part 3 for details on changing this attribute.NOTE read refers to these commands TPM2_NV_Read TPM2_NV_ReadPublic TPM_NV_Certify TPM2_PolicyNVwrite refers to these commands TPM2_NV_Write TPM2_NV_Increment TPM2_NV_Extend TPM2_NV_SetBitsNOTE The TPM must query the index TPMA_PLATFORM_CREATE attribute to determine whether phEnableNV is applicable. Since the TPM will return TPM2_RC_HANDLE if the index does not exist it also returns this error code if the index is disabled. Otherwise the TPM would leak the existence of an index even when disabled.  */
	unsigned int ehEnable : 1;	/* SET 1 The EPS hierarchy is enabled and Endorsement Authorization may be used to authorize commands.CLEAR 0 Endorsement Authorization may not be used for authorizations and objects in the endorsement hierarchy including persistent objects cannot be used.NOTE	See TPM2_HierarchyControl in TPM 2.0 Part 3 for details on changing this attribute.  */
	unsigned int shEnable : 1;	/* SET 1 The Storage hierarchy is enabled and ownerAuth or ownerPolicy may be used for authorization. NV indices defined using owner authorization are accessible.CLEAR 0 ownerAuth and ownerPolicy may not be used for authorizations and objects in the Storage hierarchy persistent objects and NV indices defined using owner authorization cannot be used.NOTE	See TPM2_HierarchyControl in TPM 2.0 Part 3 for details on changing this attribute.  */
	unsigned int phEnable : 1;	/* SET 1 The platform hierarchy is enabled and platformAuth or platformPolicy may be used for authorization.CLEAR 0 platformAuth and platformPolicy may not be used for authorizations and objects in the platform hierarchy including persistent objects cannot be used.NOTE	See TPM2_HierarchyControl in TPM 2.0 Part 3 for details on changing this attribute.  */
	};
	UINT32 val;
} TPMA_STARTUP_CLEAR;

#else

typedef uint32_t	TPMA_STARTUP_CLEAR;

#endif

#define TPMA_STARTUP_CLEAR_PHENABLE	0x00000001
#define TPMA_STARTUP_CLEAR_SHENABLE	0x00000002
#define TPMA_STARTUP_CLEAR_EHENABLE	0x00000004
#define TPMA_STARTUP_CLEAR_PHENABLENV	0x00000008
#define TPMA_STARTUP_CLEAR_RESERVED1	0x7FFFFFF0
#define TPMA_STARTUP_CLEAR_ORDERLY	0x80000000


/* Table 36  Definition of UINT32 TPMA_MEMORY Bits <Out> */
#if defined TPM_BITFIELD_LE

typedef union {
	struct {
	unsigned int sharedRAM : 1;	/* SET 1 indicates that the RAM memory used for authorization session contexts is shared with the memory used for transient objectsCLEAR 0 indicates that the memory used for authorization sessions is not shared with memory used for transient objects   */
	unsigned int sharedNV : 1;	/* SET 1 indicates that the NV memory used for persistent objects is shared with the NV memory used for NV Index valuesCLEAR 0 indicates that the persistent objects and NV Index values are allocated from separate sections of NV  */
	unsigned int objectCopiedToRam : 1;	/* SET 1 indicates that the TPM copies persistent objects to a transientobject slot in RAM when the persistent object is referenced in a command. The TRM is required to make sure that an object slot is available.CLEAR 0 indicates that the TPM does not use transientobject slots when persistent objects are referenced  */
	unsigned int reserved1 : 29;	/* shall be zero  */
	};
	UINT32 val;
} TPMA_MEMORY;

#elif defined TPM_BITFIELD_BE

typedef union {
	struct {
	unsigned int reserved1 : 29;	/* shall be zero  */
	unsigned int objectCopiedToRam : 1;	/* SET 1 indicates that the TPM copies persistent objects to a transientobject slot in RAM when the persistent object is referenced in a command. The TRM is required to make sure that an object slot is available.CLEAR 0 indicates that the TPM does not use transientobject slots when persistent objects are referenced  */
	unsigned int sharedNV : 1;	/* SET 1 indicates that the NV memory used for persistent objects is shared with the NV memory used for NV Index valuesCLEAR 0 indicates that the persistent objects and NV Index values are allocated from separate sections of NV  */
	unsigned int sharedRAM : 1;	/* SET 1 indicates that the RAM memory used for authorization session contexts is shared with the memory used for transient objectsCLEAR 0 indicates that the memory used for authorization sessions is not shared with memory used for transient objects   */
	};
	UINT32 val;
} TPMA_MEMORY;

#else

typedef uint32_t	TPMA_MEMORY;

#endif

#define TPMA_MEMORY_SHAREDRAM	0x00000001
#define TPMA_MEMORY_SHAREDNV	0x00000002
#define TPMA_MEMORY_OBJECTCOPIEDTORAM	0x00000004
#define TPMA_MEMORY_RESERVED1	0xFFFFFFF8


/* Table 37  Definition of TPM2_CC TPMA_CC Bits <OUT> */
#if defined TPM_BITFIELD_LE

typedef union {
	struct {
	unsigned int commandIndex : 16;	/* indicates the command being selected  */
	unsigned int reserved1 : 6;	/* shall be zero  */
	unsigned int nv : 1;	/* SET 1 indicates that the command may write to NVCLEAR 0 indicates that the command does not write to NV  */
	unsigned int extensive : 1;	/* SET 1 This command could flush any number of loaded contexts.CLEAR 0 no additional changes other than indicated by the flushed attribute  */
	unsigned int flushed : 1;	/* SET 1 The context associated with any transient handle in the command will be flushed when this command completes.CLEAR 0 No context is flushed as a side effect of this command.  */
	unsigned int cHandles : 3;	/* indicates the number of the handles in the handle area for this command  */
	unsigned int rHandle : 1;	/* SET 1 indicates the presence of the handle area in the response  */
	unsigned int V : 1;	/* SET 1 indicates that the command is vendorspecificCLEAR 0 indicates that the command is defined in a version of this specification  */
	unsigned int Res : 2;	/* allocated for software shall be zero  */
	};
	UINT32 val;
} TPMA_CC;

#elif defined TPM_BITFIELD_BE

typedef union {
	struct {
	unsigned int Res : 2;	/* allocated for software shall be zero  */
	unsigned int V : 1;	/* SET 1 indicates that the command is vendorspecificCLEAR 0 indicates that the command is defined in a version of this specification  */
	unsigned int rHandle : 1;	/* SET 1 indicates the presence of the handle area in the response  */
	unsigned int cHandles : 3;	/* indicates the number of the handles in the handle area for this command  */
	unsigned int flushed : 1;	/* SET 1 The context associated with any transient handle in the command will be flushed when this command completes.CLEAR 0 No context is flushed as a side effect of this command.  */
	unsigned int extensive : 1;	/* SET 1 This command could flush any number of loaded contexts.CLEAR 0 no additional changes other than indicated by the flushed attribute  */
	unsigned int nv : 1;	/* SET 1 indicates that the command may write to NVCLEAR 0 indicates that the command does not write to NV  */
	unsigned int reserved1 : 6;	/* shall be zero  */
	unsigned int commandIndex : 16;	/* indicates the command being selected  */
	};
	UINT32 val;
} TPMA_CC;

#else

typedef uint32_t	TPMA_CC;

#endif

#define TPMA_CC_COMMANDINDEX_SHIFT            0
#define TPMA_CC_COMMANDINDEX	0x0000FFFF
#define TPMA_CC_RESERVED1	0x003F0000
#define TPMA_CC_NV	0x00400000
#define TPMA_CC_EXTENSIVE	0x00800000
#define TPMA_CC_FLUSHED	0x01000000
#define TPMA_CC_CHANDLES	0x0E000000
#define TPMA_CC_RHANDLE	0x10000000
#define TPMA_CC_V	0x20000000
#define TPMA_CC_RES	0xC0000000
#define TPMA_CC_RES_SHIFT 30


/* Table 38  Definition of UINT32 TPMA_MODES Bits <Out> */
#if defined TPM_BITFIELD_LE

typedef union {
	struct {
	unsigned int FIPS_140_2 : 1;	/* SET 1 indicates that the TPM is designed to comply with all of the FIPS 1402 requirements at Level 1 or higher.  */
	unsigned int reserved1 : 31;	/* shall be zero  */
	};
	UINT32 val;
} TPMA_MODES;

#elif defined TPM_BITFIELD_BE

typedef union {
	struct {
	unsigned int reserved1 : 31;	/* shall be zero  */
	unsigned int FIPS_140_2 : 1;	/* SET 1 indicates that the TPM is designed to comply with all of the FIPS 1402 requirements at Level 1 or higher.  */
	};
	UINT32 val;
} TPMA_MODES;

#else

typedef uint32_t	TPMA_MODES;

#endif

#define TPMA_MODES_FIPS_140_2	0x00000001
#define TPMA_MODES_RESERVED1	0xFFFFFFFE


/* Table 39  Definition of BYTE TPMI_YES_NO Type */
typedef	BYTE TPMI_YES_NO;

/* Table 40  Definition of TPM2_HANDLE TPMI_DH_OBJECT Type  */
typedef	TPM2_HANDLE TPMI_DH_OBJECT;

/* Table 41  Definition of TPM2_HANDLE TPMI_DH_PERSISTENT Type  */
typedef	TPM2_HANDLE TPMI_DH_PERSISTENT;

/* Table 42  Definition of TPM2_HANDLE TPMI_DH_ENTITY Type <IN> */
typedef	TPM2_HANDLE TPMI_DH_ENTITY;

/* Table 43  Definition of TPM2_HANDLE TPMI_DH_PCR Type <IN> */
typedef	TPM2_HANDLE TPMI_DH_PCR;

/* Table 44  Definition of TPM2_HANDLE TPMI_SH_AUTH_SESSION Type <INOUT> */
typedef	TPM2_HANDLE TPMI_SH_AUTH_SESSION;

/* Table 45  Definition of TPM2_HANDLE TPMI_SH_HMAC Type <INOUT> */
typedef	TPM2_HANDLE TPMI_SH_HMAC;

/* Table 46  Definition of TPM2_HANDLE TPMI_SH_POLICY Type <INOUT> */
typedef	TPM2_HANDLE TPMI_SH_POLICY;

/* Table 47  Definition of TPM2_HANDLE TPMI_DH_CONTEXT Type  */
typedef	TPM2_HANDLE TPMI_DH_CONTEXT;

/* Table 48  Definition of TPM2_HANDLE TPMI_RH_HIERARCHY Type  */
typedef	TPM2_HANDLE TPMI_RH_HIERARCHY;

/* Table 49  Definition of TPM2_HANDLE TPMI_RH_ENABLES Type  */
typedef	TPM2_HANDLE TPMI_RH_ENABLES;

/* Table 50  Definition of TPM2_HANDLE TPMI_RH_HIERARCHY_AUTH Type <IN> */
typedef	TPM2_HANDLE TPMI_RH_HIERARCHY_AUTH;

/* Table 51  Definition of TPM2_HANDLE TPMI_RH_PLATFORM Type <IN> */
typedef	TPM2_HANDLE TPMI_RH_PLATFORM;

/* Table 52  Definition of TPM2_HANDLE TPMI_RH_OWNER Type <IN> */
typedef	TPM2_HANDLE TPMI_RH_OWNER;

/* Table 53  Definition of TPM2_HANDLE TPMI_RH_ENDORSEMENT Type <IN> */
typedef	TPM2_HANDLE TPMI_RH_ENDORSEMENT;

/* Table 54  Definition of TPM2_HANDLE TPMI_RH_PROVISION Type <IN> */
typedef	TPM2_HANDLE TPMI_RH_PROVISION;

/* Table 55  Definition of TPM2_HANDLE TPMI_RH_CLEAR Type <IN> */
typedef	TPM2_HANDLE TPMI_RH_CLEAR;

/* Table 56  Definition of TPM2_HANDLE TPMI_RH_NV_AUTH Type <IN> */
typedef	TPM2_HANDLE TPMI_RH_NV_AUTH;

/* Table 57  Definition of TPM2_HANDLE TPMI_RH_LOCKOUT Type <IN> */
typedef	TPM2_HANDLE TPMI_RH_LOCKOUT;

/* Table 58  Definition of TPM2_HANDLE TPMI_RH_NV_INDEX Type <INOUT> */
typedef	TPM2_HANDLE TPMI_RH_NV_INDEX;

/* Table 59  Definition of TPM2_ALG_ID TPMI_ALG_HASH Type  */
typedef	TPM2_ALG_ID TPMI_ALG_HASH;

/* Table 60  Definition of TPM2_ALG_ID TPMI_ALG_ASYM Type */
typedef	TPM2_ALG_ID TPMI_ALG_ASYM;

/* Table 61  Definition of TPM2_ALG_ID TPMI_ALG_SYM Type */
typedef	TPM2_ALG_ID TPMI_ALG_SYM;

/* Table 62  Definition of TPM2_ALG_ID TPMI_ALG_SYM_OBJECT Type */
typedef	TPM2_ALG_ID TPMI_ALG_SYM_OBJECT;

/* Table 63  Definition of TPM2_ALG_ID TPMI_ALG_SYM_MODE Type */
typedef	TPM2_ALG_ID TPMI_ALG_SYM_MODE;

/* Table 64  Definition of TPM2_ALG_ID TPMI_ALG_KDF Type */
typedef	TPM2_ALG_ID TPMI_ALG_KDF;

/* Table 65  Definition of TPM2_ALG_ID TPMI_ALG_SIG_SCHEME Type */
typedef	TPM2_ALG_ID TPMI_ALG_SIG_SCHEME;

/* Table 66  Definition of TPM2_ALG_IDECC TPMI_ECC_KEY_EXCHANGE Type */
typedef	TPM2_ALG_ID TPMI_ECC_KEY_EXCHANGE;

/* Table 67  Definition of TPM2_ST TPMI_ST_COMMAND_TAG Type */
typedef	TPM2_ST TPMI_ST_COMMAND_TAG;

/* Table 68  Definition of TPMS_EMPTY Structure <INOUT> */
typedef	struct {
	BYTE empty[1];	 /* a structure with no member  */
} TPMS_EMPTY;

/* Table 69  Definition of TPMS_ALGORITHM_DESCRIPTION Structure <OUT> */
typedef	struct {
	TPM2_ALG_ID	alg;	 /* an algorithm  */
	TPMA_ALGORITHM	attributes;	 /* the attributes of the algorithm  */
} TPMS_ALGORITHM_DESCRIPTION;

/* Table 70  Definition of TPMU_HA Union <INOUT S> */
typedef	union {
	BYTE	sha1[TPM2_SHA1_DIGEST_SIZE];	 /* all hashes  */
	BYTE	sha256[TPM2_SHA256_DIGEST_SIZE];	 /* all hashes  */
	BYTE	sha384[TPM2_SHA384_DIGEST_SIZE];	 /* all hashes  */
	BYTE	sha512[TPM2_SHA512_DIGEST_SIZE];	 /* all hashes  */
	BYTE	sm3_256[TPM2_SM3_256_DIGEST_SIZE];	 /* all hashes  */
} TPMU_HA;

/* Table 71  Definition of TPMT_HA Structure <INOUT> */
typedef	struct {
	TPMI_ALG_HASH	hashAlg;	 /* selector of the hash contained in the digest that implies the size of the digestNOTE	The leading + on the type indicates that this structure should pass an indication to the unmarshaling function for TPMI_ALG_HASH so that TPM2_ALG_NULL will be allowed if a use of a TPMT_HA allows TPM2_ALG_NULL.   */
	TPMU_HA	digest;	 /* the digest data   */
} TPMT_HA;

/* Table 72  Definition of TPM2B_DIGEST Structure */
TPM2B_TYPE1( DIGEST, sizeof(TPMU_HA), buffer );

/* Table 73  Definition of TPM2B_DATA Structure */
TPM2B_TYPE1( DATA, sizeof(TPMT_HA), buffer );

/* Table 74  Definition of Types for TPM2B_NONCE */
typedef	TPM2B_DIGEST	TPM2B_NONCE;	 /* size limited to the same as the digest structure  */

/* Table 75  Definition of Types for TPM2B_AUTH */
typedef	TPM2B_DIGEST	TPM2B_AUTH;	 /* size limited to the same as the digest structure  */

/* Table 76  Definition of Types for TPM2B_OPERAND */
typedef	TPM2B_DIGEST	TPM2B_OPERAND;	 /* size limited to the same as the digest structure  */

/* Table 77  Definition of TPM2B_EVENT Structure */
TPM2B_TYPE1( EVENT, 1024, buffer );

/* Table 78  Definition of TPM2B_MAX_BUFFER Structure */
TPM2B_TYPE1( MAX_BUFFER, TPM2_MAX_DIGEST_BUFFER, buffer );

/* Table 79  Definition of TPM2B_MAX_NV_BUFFER Structure */
TPM2B_TYPE1( MAX_NV_BUFFER, TPM2_MAX_NV_BUFFER_SIZE, buffer );

/* Table 80  Definition of Types for TPM2B_TIMEOUT */
typedef	TPM2B_DIGEST	TPM2B_TIMEOUT;	 /* size limited to the same as the digest structure  */

/* Table 81  Definition of TPM2B_IV Structure <INOUT> */
TPM2B_TYPE1( IV, TPM2_MAX_SYM_BLOCK_SIZE, buffer );

/* Table 82  Definition of TPMU_NAME Union <> */
typedef	union {
	TPMT_HA	digest;	 /* when the Name is a digest  */
	TPM2_HANDLE	handle;	 /* when the Name is a handle  */
} TPMU_NAME;

/* Table 83  Definition of TPM2B_NAME Structure */
TPM2B_TYPE1( NAME, sizeof(TPMU_NAME), name );

/* Table 84  Definition of TPMS_PCR_SELECT Structure */
typedef	struct {
	UINT8	sizeofSelect;	 /* the size in octets of the pcrSelect array  */
	BYTE	pcrSelect[TPM2_PCR_SELECT_MAX];	 /* the bit map of selected PCR  */
} TPMS_PCR_SELECT;

/* Table 85  Definition of TPMS_PCR_SELECTION Structure */
typedef	struct {
	TPMI_ALG_HASH	hash;	 /* the hash algorithm associated with the selection  */
	UINT8	sizeofSelect;	 /* the size in octets of the pcrSelect array  */
	BYTE	pcrSelect[TPM2_PCR_SELECT_MAX];	 /* the bit map of selected PCR  */
} TPMS_PCR_SELECTION;

/* Table 88  Definition of TPMT_TK_CREATION Structure */
typedef	struct {
	TPM2_ST	tag;	 /* ticket structure tag  */
	TPMI_RH_HIERARCHY	hierarchy;	 /* the hierarchy containing name  */
	TPM2B_DIGEST	digest;	 /* This shall be the HMAC produced using a proof value of hierarchy.  */
} TPMT_TK_CREATION;

/* Table 89  Definition of TPMT_TK_VERIFIED Structure */
typedef	struct {
	TPM2_ST	tag;	 /* ticket structure tag  */
	TPMI_RH_HIERARCHY	hierarchy;	 /* the hierarchy containing keyName  */
	TPM2B_DIGEST	digest;	 /* This shall be the HMAC produced using a proof value of hierarchy.  */
} TPMT_TK_VERIFIED;

/* Table 90  Definition of TPMT_TK_AUTH Structure */
typedef	struct {
	TPM2_ST	tag;	 /* ticket structure tag  */
	TPMI_RH_HIERARCHY	hierarchy;	 /* the hierarchy of the object used to produce the ticket  */
	TPM2B_DIGEST	digest;	 /* This shall be the HMAC produced using a proof value of hierarchy.  */
} TPMT_TK_AUTH;

/* Table 91  Definition of TPMT_TK_HASHCHECK Structure */
typedef	struct {
	TPM2_ST	tag;	 /* ticket structure tag  */
	TPMI_RH_HIERARCHY	hierarchy;	 /* the hierarchy  */
	TPM2B_DIGEST	digest;	 /* This shall be the HMAC produced using a proof value of hierarchy.  */
} TPMT_TK_HASHCHECK;

/* Table 92  Definition of TPMS_ALG_PROPERTY Structure <OUT> */
typedef	struct {
	TPM2_ALG_ID	alg;	 /* an algorithm identifier  */
	TPMA_ALGORITHM	algProperties;	 /* the attributes of the algorithm  */
} TPMS_ALG_PROPERTY;

/* Table 93  Definition of TPMS_TAGGED_PROPERTY Structure <OUT> */
typedef	struct {
	TPM2_PT	property;	 /* a property identifier  */
	UINT32	value;	 /* the value of the property  */
} TPMS_TAGGED_PROPERTY;

/* Table 94  Definition of TPMS_TAGGED_PCR_SELECT Structure <OUT> */
typedef	struct {
	TPM2_PT_PCR	tag;	 /* the property identifier  */
	UINT8	sizeofSelect;	 /* the size in octets of the pcrSelect array  */
	BYTE	pcrSelect[TPM2_PCR_SELECT_MAX];	 /* the bit map of PCR with the identified property  */
} TPMS_TAGGED_PCR_SELECT;

/* Table 95  Definition of TPML_CC Structure */
typedef	struct {
	UINT32	count;	 /* number of commands in the commandCode list may be 0  */
	TPM2_CC	commandCodes[TPM2_MAX_CAP_CC];	 /* a list of command codesThe maximum only applies to a command code list in a command. The response size is limited only by the size of the parameter buffer.  */
} TPML_CC;

/* Table 96  Definition of TPML_CCA Structure <OUT> */
typedef	struct {
	UINT32	count;	 /* number of values in the commandAttributes list may be 0  */
	TPMA_CC	commandAttributes[TPM2_MAX_CAP_CC];	 /* a list of command codes attributes  */
} TPML_CCA;

/* Table 97  Definition of TPML_ALG Structure */
typedef	struct {
	UINT32	count;	 /* number of algorithms in the algorithms list may be 0  */
	TPM2_ALG_ID	algorithms[TPM2_MAX_ALG_LIST_SIZE];	 /* a list of algorithm IDsThe maximum only applies to an algorithm list in a command. The response size is limited only by the size of the parameter buffer.  */
} TPML_ALG;

/* Table 98  Definition of TPML_HANDLE Structure <OUT> */
typedef	struct {
	UINT32	count;	 /* the number of handles in the listmay have a value of 0  */
	TPM2_HANDLE	handle[TPM2_MAX_CAP_HANDLES];	 /* an array of handles  */
} TPML_HANDLE;

/* Table 99  Definition of TPML_DIGEST Structure */
typedef	struct {
	UINT32	count;	 /* number of digests in the list minimum is two for TPM2_PolicyOR.   */
	TPM2B_DIGEST	digests[8];	 /* a list of digestsFor TPM2_PolicyOR all digests will have been computed using the digest of the policy session. For TPM2_PCR_Read each digest will be the size of the digest for the bank containing the PCR.  */
} TPML_DIGEST;

/* Table 100  Definition of TPML_DIGEST_VALUES Structure */
typedef	struct {
	UINT32	count;	 /* number of digests in the list  */
	TPMT_HA	digests[TPM2_NUM_PCR_BANKS];	 /* a list of tagged digests  */
} TPML_DIGEST_VALUES;

/* Table 101  Definition of TPM2B_DIGEST_VALUES Structure */
TPM2B_TYPE1( DIGEST_VALUES, sizeof(TPML_DIGEST_VALUES), buffer );

/* Table 102  Definition of TPML_PCR_SELECTION Structure */
typedef	struct {
	UINT32	count;	 /* number of selection structuresA value of zero is allowed.  */
	TPMS_PCR_SELECTION	pcrSelections[TPM2_NUM_PCR_BANKS];	 /* list of selections  */
} TPML_PCR_SELECTION;

/* Table 103  Definition of TPML_ALG_PROPERTY Structure <OUT> */
typedef	struct {
	UINT32	count;	 /* number of algorithm properties structuresA value of zero is allowed.  */
	TPMS_ALG_PROPERTY	algProperties[TPM2_MAX_CAP_ALGS];	 /* list of properties  */
} TPML_ALG_PROPERTY;

/* Table 104  Definition of TPML_TAGGED_TPM_PROPERTY Structure <OUT> */
typedef	struct {
	UINT32	count;	 /* number of propertiesA value of zero is allowed.  */
	TPMS_TAGGED_PROPERTY	tpmProperty[TPM2_MAX_TPM_PROPERTIES];	 /* an array of tagged properties  */
} TPML_TAGGED_TPM_PROPERTY;

/* Table 105  Definition of TPML_TAGGED_PCR_PROPERTY Structure <OUT> */
typedef	struct {
	UINT32	count;	 /* number of propertiesA value of zero is allowed.  */
	TPMS_TAGGED_PCR_SELECT	pcrProperty[TPM2_MAX_PCR_PROPERTIES];	 /* a tagged PCR selection  */
} TPML_TAGGED_PCR_PROPERTY;

/* Table 106  Definition of ECC TPML_ECC_CURVE Structure <OUT> */
typedef	struct {
	UINT32	count;	 /* number of curvesA value of zero is allowed.  */
	TPM2_ECC_CURVE	eccCurves[TPM2_MAX_ECC_CURVES];	 /* array of ECC curve identifiers  */
} TPML_ECC_CURVE;

/* Implementation specific structure to hold Intel PTT specific property data. */
typedef	struct {
	UINT32	count;	/* number of properties zero is allowed.  */
	UINT32	property[TPM2_MAX_PTT_PROPERTIES];	/* property value */
} TPML_INTEL_PTT_PROPERTY;

/* Table 107  Definition of TPMU_CAPABILITIES Union <OUT> */
typedef	union {
	TPML_ALG_PROPERTY	algorithms;	 /*   */
	TPML_HANDLE	handles;	 /*   */
	TPML_CCA	command;	 /*   */
	TPML_CC	ppCommands;	 /*   */
	TPML_CC	auditCommands;	 /*   */
	TPML_PCR_SELECTION	assignedPCR;	 /*   */
	TPML_TAGGED_TPM_PROPERTY	tpmProperties;	 /*   */
	TPML_TAGGED_PCR_PROPERTY	pcrProperties;	 /*   */
	TPML_ECC_CURVE	eccCurves;	 /* TPM2_ALG_ECC  */
	TPML_INTEL_PTT_PROPERTY	intelPttProperty;
} TPMU_CAPABILITIES;

/* Table 108  Definition of TPMS_CAPABILITY_DATA Structure <OUT> */
typedef	struct {
	TPM2_CAP	capability;	 /* the capability  */
	TPMU_CAPABILITIES	data;	 /* the capability data  */
} TPMS_CAPABILITY_DATA;

/* Table 109  Definition of TPMS_CLOCK_INFO Structure */
typedef	struct {
	UINT64	clock;	 /* time in milliseconds during which the TPM has been poweredThis structure element is used to report on the TPMs Clock value.The value of Clock shall be recorded in nonvolatile memory no less often than once per 222 milliseconds 69.9 minutes of TPM operation. The reference for the millisecond timer is the TPM oscillator.This value is reset to zero when the Storage Primary Seed is changed TPM2_Clear.This value may be advanced by TPM2_AdvanceClock.  */
	UINT32	resetCount;	 /* number of occurrences of TPM Reset since the last TPM2_Clear  */
	UINT32	restartCount;	 /* number of times that TPM2_Shutdown or _TPM_Hash_Start have occurred since the last TPM Reset or TPM2_Clear.  */
	TPMI_YES_NO	safe;	 /* no value of Clock greater than the current value of Clock has been previously reported by the TPM. Set to YES on TPM2_Clear.  */
} TPMS_CLOCK_INFO;

/* Table 110  Definition of TPMS_TIME_INFO Structure */
typedef	struct {
	UINT64	time;	 /* time in milliseconds since the last _TPM_Init or TPM2_StartupThis structure element is used to report on the TPMs Time value.  */
	TPMS_CLOCK_INFO	clockInfo;	 /* a structure containing the clock information  */
} TPMS_TIME_INFO;

/* Table 111  Definition of TPMS_TIME_ATTEST_INFO Structure <OUT> */
typedef	struct {
	TPMS_TIME_INFO	time;	 /* the Time Clock resetCount restartCount and Safe indicator  */
	UINT64	firmwareVersion;	 /* a TPM vendorspecific value indicating the version number of the firmware  */
} TPMS_TIME_ATTEST_INFO;

/* Table 112  Definition of TPMS_CERTIFY_INFO Structure <OUT> */
typedef	struct {
	TPM2B_NAME	name;	 /* Name of the certified object  */
	TPM2B_NAME	qualifiedName;	 /* Qualified Name of the certified object  */
} TPMS_CERTIFY_INFO;

/* Table 113  Definition of TPMS_QUOTE_INFO Structure <OUT> */
typedef	struct {
	TPML_PCR_SELECTION	pcrSelect;	 /* information on algID PCR selected and digest  */
	TPM2B_DIGEST	pcrDigest;	 /* digest of the selected PCR using the hash of the signing key  */
} TPMS_QUOTE_INFO;

/* Table 114  Definition of TPMS_COMMAND_AUDIT_INFO Structure <OUT> */
typedef	struct {
	UINT64	auditCounter;	 /* the monotonic audit counter  */
	TPM2_ALG_ID	digestAlg;	 /* hash algorithm used for the command audit  */
	TPM2B_DIGEST	auditDigest;	 /* the current value of the audit digest  */
	TPM2B_DIGEST	commandDigest;	 /* digest of the command codes being audited using digestAlg  */
} TPMS_COMMAND_AUDIT_INFO;

/* Table 115  Definition of TPMS_SESSION_AUDIT_INFO Structure <OUT> */
typedef	struct {
	TPMI_YES_NO	exclusiveSession;	 /* current exclusive status of the session TRUE if all of the commands recorded in the sessionDigest were executed without any intervening TPM command that did not use this audit session  */
	TPM2B_DIGEST	sessionDigest;	 /* the current value of the session audit digest  */
} TPMS_SESSION_AUDIT_INFO;

/* Table 116  Definition of TPMS_CREATION_INFO Structure <OUT> */
typedef	struct {
	TPM2B_NAME	objectName;	 /* Name of the object  */
	TPM2B_DIGEST	creationHash;	 /* creationHash  */
} TPMS_CREATION_INFO;

/* Table 117  Definition of TPMS_NV_CERTIFY_INFO Structure <OUT> */
typedef	struct {
	TPM2B_NAME	indexName;	 /* Name of the NV Index  */
	UINT16	offset;	 /* the offset parameter of TPM2_NV_Certify  */
	TPM2B_MAX_NV_BUFFER	nvContents;	 /* contents of the NV Index  */
} TPMS_NV_CERTIFY_INFO;

/* Table 118  Definition of TPM2_ST TPMI_ST_ATTEST Type <OUT> */
typedef	TPM2_ST TPMI_ST_ATTEST;

/* Table 119  Definition of TPMU_ATTEST Union <OUT> */
typedef	union {
	TPMS_CERTIFY_INFO	certify;	 /*  */
	TPMS_CREATION_INFO	creation;	 /*  */
	TPMS_QUOTE_INFO	quote;	 /*  */
	TPMS_COMMAND_AUDIT_INFO	commandAudit;	 /*  */
	TPMS_SESSION_AUDIT_INFO	sessionAudit;	 /*  */
	TPMS_TIME_ATTEST_INFO	time;	 /*  */
	TPMS_NV_CERTIFY_INFO	nv;	 /*  */
} TPMU_ATTEST;

/* Table 120  Definition of TPMS_ATTEST Structure <OUT> */
typedef	struct {
	TPM2_GENERATED	magic;	 /* the indication that this structure was created by a TPM always TPM2_GENERATED_VALUE  */
	TPMI_ST_ATTEST	type;	 /* type of the attestation structure  */
	TPM2B_NAME	qualifiedSigner;	 /* Qualified Name of the signing key  */
	TPM2B_DATA	extraData;	 /* external information supplied by callerNOTE	A TPM2B_DATA structure provides room for a digest and a method indicator to indicate the components of the digest. The definition of this method indicator is outside the scope of this specification.  */
	TPMS_CLOCK_INFO	clockInfo;	 /* Clock resetCount restartCount and Safe  */
	UINT64	firmwareVersion;	 /* TPMvendorspecific value identifying the version number of the firmware  */
	TPMU_ATTEST	attested;	 /* the typespecific attestation information  */
} TPMS_ATTEST;

/* Table 121  Definition of TPM2B_ATTEST Structure <OUT> */
TPM2B_TYPE1( ATTEST, sizeof(TPMS_ATTEST), attestationData );

/* Table 122  Definition of TPMS_AUTH_COMMAND Structure <IN> */
typedef	struct {
	TPMI_SH_AUTH_SESSION	sessionHandle;	 /* the session handle  */
	TPM2B_NONCE	nonce;	 /* the session nonce may be the Empty Buffer  */
	TPMA_SESSION	sessionAttributes;	 /* the session attributes  */
	TPM2B_AUTH	hmac;	 /* either an HMAC a password or an EmptyAuth  */
} TPMS_AUTH_COMMAND;

/* Table 123  Definition of TPMS_AUTH_RESPONSE Structure <OUT> */
typedef	struct {
	TPM2B_NONCE	nonce;	 /* the session nonce may be the Empty Buffer  */
	TPMA_SESSION	sessionAttributes;	 /* the session attributes  */
	TPM2B_AUTH	hmac;	 /* either an HMAC or an EmptyAuth  */
} TPMS_AUTH_RESPONSE;

/* Table 124  Definition of  AES TPM2_KEY_BITS TPMI_AES_KEY_BITS   Type */
typedef	TPM2_KEY_BITS TPMI_AES_KEY_BITS;

/* Table 124  Definition of  SM4 TPM2_KEY_BITS TPMI_SM4_KEY_BITS   Type */
typedef	TPM2_KEY_BITS TPMI_SM4_KEY_BITS;

/* Table 124  Definition of  CAMELLIA TPM2_KEY_BITS TPMI_TPM2_CAMELLIA_KEY_BITS   Type */
typedef	TPM2_KEY_BITS TPMI_TPM2_CAMELLIA_KEY_BITS;

/* Table 125  Definition of TPMU_SYM_KEY_BITS Union */
typedef	union {
	TPMI_AES_KEY_BITS	aes;	 /* all symmetric algorithms  */
	TPMI_SM4_KEY_BITS	sm4;	 /* all symmetric algorithms  */
	TPMI_TPM2_CAMELLIA_KEY_BITS	camellia;	 /* all symmetric algorithms  */
	TPM2_KEY_BITS	sym;	 /* when selector may be any of the symmetric block ciphers  */
	TPMI_ALG_HASH	exclusiveOr;	 /* overload for using xorNOTE	TPM2_ALG_NULL is not allowed  */
} TPMU_SYM_KEY_BITS;

/* Table 126  Definition of TPMU_SYM_MODE Union */
typedef	union {
	TPMI_ALG_SYM_MODE	aes;	 /*   */
	TPMI_ALG_SYM_MODE	sm4;	 /*   */
	TPMI_ALG_SYM_MODE	camellia;	 /*   */
	TPMI_ALG_SYM_MODE	sym;	 /* when selector may be any of the symmetric block ciphers  */
} TPMU_SYM_MODE;

/* Table 128  Definition of TPMT_SYM_DEF Structure */
typedef	struct {
	TPMI_ALG_SYM	algorithm;	 /* indicates a symmetric algorithm   */
	TPMU_SYM_KEY_BITS	keyBits;	 /* a supported key size  */
	TPMU_SYM_MODE	mode;	 /* the mode for the key  */
} TPMT_SYM_DEF;

/* Table 129  Definition of TPMT_SYM_DEF_OBJECT Structure */
typedef	struct {
	TPMI_ALG_SYM_OBJECT	algorithm;	 /* selects a symmetric block cipher   */
	TPMU_SYM_KEY_BITS	keyBits;	 /* the key size  */
	TPMU_SYM_MODE	mode;	 /* default mode  */
} TPMT_SYM_DEF_OBJECT;

/* Table 130  Definition of TPM2B_SYM_KEY Structure */
TPM2B_TYPE1( SYM_KEY, TPM2_MAX_SYM_KEY_BYTES, buffer );

/* Table 131  Definition of TPMS_SYMCIPHER_PARMS Structure */
typedef	struct {
	TPMT_SYM_DEF_OBJECT	sym;	 /* a symmetric block cipher  */
} TPMS_SYMCIPHER_PARMS;

/* Table 132  Definition of TPM2B_SENSITIVE_DATA Structure */
TPM2B_TYPE1( SENSITIVE_DATA, TPM2_MAX_SYM_DATA, buffer );

/* Table 133  Definition of TPMS_SENSITIVE_CREATE Structure <IN> */
typedef	struct {
	TPM2B_AUTH	userAuth;	 /* the USER auth secret value  */
	TPM2B_SENSITIVE_DATA	data;	 /* data to be sealed  */
} TPMS_SENSITIVE_CREATE;

/* Table 134  Definition of TPM2B_SENSITIVE_CREATE Structure <IN S> */
TPM2B_TYPE2( SENSITIVE_CREATE, TPMS_SENSITIVE_CREATE, sensitive );

/* Table 135  Definition of TPMS_SCHEME_HASH Structure */
typedef	struct {
	TPMI_ALG_HASH	hashAlg;	 /* the hash algorithm used to digest the message  */
} TPMS_SCHEME_HASH;

/* Table 136  Definition of ECC TPMS_SCHEME_ECDAA Structure */
typedef	struct {
	TPMI_ALG_HASH	hashAlg;	 /* the hash algorithm used to digest the message  */
	UINT16	count;	 /* the counter value that is used between TPM2_Commit and the sign operation  */
} TPMS_SCHEME_ECDAA;

/* Table 137  Definition of TPM2_ALG_ID TPMI_ALG_KEYEDHASH_SCHEME Type */
typedef	TPM2_ALG_ID TPMI_ALG_KEYEDHASH_SCHEME;

/* Table 138  Definition of Types for HMAC_SIG_SCHEME */
typedef	TPMS_SCHEME_HASH	TPMS_SCHEME_HMAC;	 /*   */

/* Table 139  Definition of TPMS_SCHEME_XOR Structure */
typedef	struct {
	TPMI_ALG_HASH	hashAlg;	 /* the hash algorithm used to digest the message  */
	TPMI_ALG_KDF	kdf;	 /* the key derivation function  */
} TPMS_SCHEME_XOR;

/* Table 140  Definition of TPMU_SCHEME_KEYEDHASH Union <INOUT S> */
typedef	union {
	TPMS_SCHEME_HMAC	hmac;	 /* the signing scheme  */
	TPMS_SCHEME_XOR	exclusiveOr;	 /* the obfuscation scheme  */
} TPMU_SCHEME_KEYEDHASH;

/* Table 141  Definition of TPMT_KEYEDHASH_SCHEME Structure */
typedef	struct {
	TPMI_ALG_KEYEDHASH_SCHEME	scheme;	 /* selects the scheme   */
	TPMU_SCHEME_KEYEDHASH	details;	 /* the scheme parameters  */
} TPMT_KEYEDHASH_SCHEME;

/* Table 142  Definition of RSA Types for RSA Signature Schemes  */
typedef	TPMS_SCHEME_HASH	TPMS_SIG_SCHEME_RSASSA;	 /*   */
typedef	TPMS_SCHEME_HASH	TPMS_SIG_SCHEME_RSAPSS;	 /*   */

/* Table 143  Definition of ECC Types for ECC Signature Schemes  */
typedef	TPMS_SCHEME_HASH	TPMS_SIG_SCHEME_ECDSA;	 /* all asymmetric signing schemes  */
typedef	TPMS_SCHEME_HASH	TPMS_SIG_SCHEME_SM2;	 /* all asymmetric signing schemes  */
typedef	TPMS_SCHEME_HASH	TPMS_SIG_SCHEME_ECSCHNORR;	 /* all asymmetric signing schemes  */
typedef	TPMS_SCHEME_ECDAA	TPMS_SIG_SCHEME_ECDAA;	 /* schemes that need a hash and a count  */

/* Table 144  Definition of TPMU_SIG_SCHEME Union <INOUT S> */
typedef	union {
	TPMS_SIG_SCHEME_RSASSA	rsassa;	 /* all signing schemes including anonymous schemes  */
	TPMS_SIG_SCHEME_RSAPSS	rsapss;	 /* all signing schemes including anonymous schemes  */
	TPMS_SIG_SCHEME_ECDSA	ecdsa;	 /* all signing schemes including anonymous schemes  */
	TPMS_SIG_SCHEME_ECDAA	ecdaa;	 /* all signing schemes including anonymous schemes  */
	TPMS_SIG_SCHEME_SM2	sm2;	 /* all signing schemes including anonymous schemes  */
	TPMS_SIG_SCHEME_ECSCHNORR	ecschnorr;	 /* all signing schemes including anonymous schemes  */
	TPMS_SCHEME_HMAC	hmac;	 /* the HMAC scheme  */
	TPMS_SCHEME_HASH	any;	 /* selector that allows access to digest for any signing scheme  */
} TPMU_SIG_SCHEME;

/* Table 145  Definition of TPMT_SIG_SCHEME Structure */
typedef	struct {
	TPMI_ALG_SIG_SCHEME	scheme;	 /* scheme selector   */
	TPMU_SIG_SCHEME	details;	 /* scheme parameters  */
} TPMT_SIG_SCHEME;

/* Table 146  Definition of Types for RSA Encryption Schemes */
typedef	TPMS_SCHEME_HASH	TPMS_ENC_SCHEME_OAEP;	 /* schemes that only need a hash  */
typedef	TPMS_EMPTY	TPMS_ENC_SCHEME_RSAES;	 /* schemes that need nothing  */

/* Table 147  Definition of Types for ECC ECC Key Exchange */
typedef	TPMS_SCHEME_HASH	TPMS_KEY_SCHEME_ECDH;	 /* schemes that need a hash  */
typedef	TPMS_SCHEME_HASH	TPMS_KEY_SCHEME_ECMQV;	 /* schemes that need a hash  */

/* Table 148  Definition of Types for KDF Schemes */
typedef	TPMS_SCHEME_HASH	TPMS_SCHEME_MGF1;	 /* hashbased key or maskgeneration functions  */
typedef	TPMS_SCHEME_HASH	TPMS_SCHEME_KDF1_SP800_56A;	 /* hashbased key or maskgeneration functions  */
typedef	TPMS_SCHEME_HASH	TPMS_SCHEME_KDF2;	 /* hashbased key or maskgeneration functions  */
typedef	TPMS_SCHEME_HASH	TPMS_SCHEME_KDF1_SP800_108;	 /* hashbased key or maskgeneration functions  */

/* Table 149  Definition of TPMU_KDF_SCHEME Union <INOUT S> */
typedef	union {
	TPMS_SCHEME_MGF1	mgf1;	 /*   */
	TPMS_SCHEME_KDF1_SP800_56A	kdf1_sp800_56a;	 /*   */
	TPMS_SCHEME_KDF2	kdf2;	 /*   */
	TPMS_SCHEME_KDF1_SP800_108	kdf1_sp800_108;	 /*   */
} TPMU_KDF_SCHEME;

/* Table 150  Definition of TPMT_KDF_SCHEME Structure */
typedef	struct {
	TPMI_ALG_KDF	scheme;	 /* scheme selector   */
	TPMU_KDF_SCHEME	details;	 /* scheme parameters  */
} TPMT_KDF_SCHEME;

/* Table 151  Definition of TPM2_ALG_ID TPMI_ALG_ASYM_SCHEME Type <> */
typedef	TPM2_ALG_ID TPMI_ALG_ASYM_SCHEME;

/* Table 152  Definition of TPMU_ASYM_SCHEME Union */
typedef	union {
	TPMS_KEY_SCHEME_ECDH	ecdh;	 /*   */
	TPMS_KEY_SCHEME_ECMQV	ecmqv;	 /*   */
	TPMS_SIG_SCHEME_RSASSA	rsassa;	 /* signing and anonymous signing  */
	TPMS_SIG_SCHEME_RSAPSS	rsapss;	 /* signing and anonymous signing  */
	TPMS_SIG_SCHEME_ECDSA	ecdsa;	 /* signing and anonymous signing  */
	TPMS_SIG_SCHEME_ECDAA	ecdaa;	 /* signing and anonymous signing  */
	TPMS_SIG_SCHEME_SM2	sm2;	 /* signing and anonymous signing  */
	TPMS_SIG_SCHEME_ECSCHNORR	ecschnorr;	 /* signing and anonymous signing  */
	TPMS_ENC_SCHEME_RSAES	rsaes;	 /* schemes with no hash  */
	TPMS_ENC_SCHEME_OAEP	oaep;	 /* schemes with no hash  */
	TPMS_SCHEME_HASH	anySig;	 /*   */
} TPMU_ASYM_SCHEME;

/* Table 153  Definition of TPMT_ASYM_SCHEME Structure <> */
typedef	struct {
	TPMI_ALG_ASYM_SCHEME	scheme;	 /* scheme selector   */
	TPMU_ASYM_SCHEME	details;	 /* scheme parameters  */
} TPMT_ASYM_SCHEME;

/* Table 154  Definition of TPM2_ALG_ID RSA TPMI_ALG_RSA_SCHEME Type */
typedef	TPM2_ALG_ID TPMI_ALG_RSA_SCHEME;

/* Table 155  Definition of RSA TPMT_RSA_SCHEME Structure */
typedef	struct {
	TPMI_ALG_RSA_SCHEME	scheme;	 /* scheme selector   */
	TPMU_ASYM_SCHEME	details;	 /* scheme parameters  */
} TPMT_RSA_SCHEME;

/* Table 156  Definition of TPM2_ALG_ID RSA TPMI_ALG_RSA_DECRYPT Type */
typedef	TPM2_ALG_ID TPMI_ALG_RSA_DECRYPT;

/* Table 157  Definition of RSA TPMT_RSA_DECRYPT Structure */
typedef	struct {
	TPMI_ALG_RSA_DECRYPT	scheme;	 /* scheme selector   */
	TPMU_ASYM_SCHEME	details;	 /* scheme parameters  */
} TPMT_RSA_DECRYPT;

/* Table 158  Definition of RSA TPM2B_PUBLIC_KEY_RSA Structure */
TPM2B_TYPE1( PUBLIC_KEY_RSA, TPM2_MAX_RSA_KEY_BYTES, buffer );

/* Table 159  Definition of RSA TPM2_KEY_BITS TPMI_RSA_KEY_BITS Type */
typedef	TPM2_KEY_BITS TPMI_RSA_KEY_BITS;

/* Table 160  Definition of RSA TPM2B_PRIVATE_KEY_RSA Structure */
TPM2B_TYPE1( PRIVATE_KEY_RSA, TPM2_MAX_RSA_KEY_BYTES/2, buffer );

/* Table 161  Definition of ECC TPM2B_ECC_PARAMETER Structure */
TPM2B_TYPE1( ECC_PARAMETER, TPM2_MAX_ECC_KEY_BYTES, buffer );

/* Table 162  Definition of ECC TPMS_ECC_POINT Structure */
typedef	struct {
	TPM2B_ECC_PARAMETER	x;	 /* X coordinate  */
	TPM2B_ECC_PARAMETER	y;	 /* Y coordinate  */
} TPMS_ECC_POINT;

/* Table 163  Definition of ECC TPM2B_ECC_POINT Structure */
TPM2B_TYPE2( ECC_POINT, TPMS_ECC_POINT, point );

/* Table 164  Definition of TPM2_ALG_ID ECC TPMI_ALG_ECC_SCHEME Type */
typedef	TPM2_ALG_ID TPMI_ALG_ECC_SCHEME;

/* Table 165  Definition of ECC TPM2_ECC_CURVE TPMI_ECC_CURVE Type */
typedef	TPM2_ECC_CURVE TPMI_ECC_CURVE;

/* Table 166  Definition of TPMT_SIG_SCHEME ECC TPMT_ECC_SCHEME Structure */
typedef	struct {
	TPMI_ALG_ECC_SCHEME	scheme;	 /* scheme selector   */
	TPMU_ASYM_SCHEME	details;	 /* scheme parameters  */
} TPMT_ECC_SCHEME;

/* Table 167  Definition of ECC TPMS_ALGORITHM_DETAIL_ECC Structure <OUT> */
typedef	struct {
	TPM2_ECC_CURVE	curveID;	 /* identifier for the curve  */
	UINT16	keySize;	 /* Size in bits of the key  */
	TPMT_KDF_SCHEME	kdf;	 /* if not TPM2_ALG_NULL the required KDF and hash algorithm used in secret sharing operations  */
	TPMT_ECC_SCHEME	sign;	 /* If not TPM2_ALG_NULL this is the mandatory signature scheme that is required to be used with this curve.  */
	TPM2B_ECC_PARAMETER	p;	 /* Fp the modulus  */
	TPM2B_ECC_PARAMETER	a;	 /* coefficient of the linear term in the curve equation  */
	TPM2B_ECC_PARAMETER	b;	 /* constant term for curve equation  */
	TPM2B_ECC_PARAMETER	gX;	 /* x coordinate of base point G  */
	TPM2B_ECC_PARAMETER	gY;	 /* y coordinate of base point G  */
	TPM2B_ECC_PARAMETER	n;	 /* order of G  */
	TPM2B_ECC_PARAMETER	h;	 /* cofactor a size of zero indicates a cofactor of 1  */
} TPMS_ALGORITHM_DETAIL_ECC;

/* Table 168  Definition of RSA TPMS_SIGNATURE_RSA Structure */
typedef	struct {
	TPMI_ALG_HASH	hash;	 /* the hash algorithm used to digest the messageTPM2_ALG_NULL is not allowed.  */
	TPM2B_PUBLIC_KEY_RSA	sig;	 /* The signature is the size of a public key.  */
} TPMS_SIGNATURE_RSA;

/* Table 169  Definition of Types for RSA Signature   */
typedef	TPMS_SIGNATURE_RSA	TPMS_SIGNATURE_RSASSA;	 /*   */
typedef	TPMS_SIGNATURE_RSA	TPMS_SIGNATURE_RSAPSS;	 /*   */

/* Table 170  Definition of ECC TPMS_SIGNATURE_ECC Structure */
typedef	struct {
	TPMI_ALG_HASH	hash;	 /* the hash algorithm used in the signature processTPM2_ALG_NULL is not allowed.  */
	TPM2B_ECC_PARAMETER	signatureR;	 /*   */
	TPM2B_ECC_PARAMETER	signatureS;	 /*   */
} TPMS_SIGNATURE_ECC;

/* Table 171  Definition of Types for ECC TPMS_SIGNATURE_ECC */
typedef	TPMS_SIGNATURE_ECC	TPMS_SIGNATURE_ECDSA;	 /*   */
typedef	TPMS_SIGNATURE_ECC	TPMS_SIGNATURE_ECDAA;	 /*   */
typedef	TPMS_SIGNATURE_ECC	TPMS_SIGNATURE_SM2;	 /*   */
typedef	TPMS_SIGNATURE_ECC	TPMS_SIGNATURE_ECSCHNORR;	 /*   */

/* Table 172  Definition of TPMU_SIGNATURE Union <INOUT S> */
typedef	union {
	TPMS_SIGNATURE_RSASSA	rsassa;	 /* all asymmetric signatures  */
	TPMS_SIGNATURE_RSAPSS	rsapss;	 /* all asymmetric signatures  */
	TPMS_SIGNATURE_ECDSA	ecdsa;	 /* all asymmetric signatures  */
	TPMS_SIGNATURE_ECDAA	ecdaa;	 /* all asymmetric signatures  */
	TPMS_SIGNATURE_SM2	sm2;	 /* all asymmetric signatures  */
	TPMS_SIGNATURE_ECSCHNORR	ecschnorr;	 /* all asymmetric signatures  */
	TPMT_HA	hmac;	 /* HMAC signature required to be supported  */
	TPMS_SCHEME_HASH	any;	 /* used to access the hash  */
} TPMU_SIGNATURE;

/* Table 173  Definition of TPMT_SIGNATURE Structure */
typedef	struct {
	TPMI_ALG_SIG_SCHEME	sigAlg;	 /* selector of the algorithm used to construct the signature  */
	TPMU_SIGNATURE	signature;	 /* This shall be the actual signature information.  */
} TPMT_SIGNATURE;

/* Table 174  Definition of TPMU_ENCRYPTED_SECRET Union <S> */
typedef	union {
	BYTE	ecc[sizeof(TPMS_ECC_POINT)];	 /*   */
	BYTE	rsa[TPM2_MAX_RSA_KEY_BYTES];	 /*   */
	BYTE	symmetric[sizeof(TPM2B_DIGEST)];	 /*   */
	BYTE	keyedHash[sizeof(TPM2B_DIGEST)];	 /* Any symmetrically encrypted secret value will be limited to be no larger than a digest.  */
} TPMU_ENCRYPTED_SECRET;

/* Table 175  Definition of TPM2B_ENCRYPTED_SECRET Structure */
TPM2B_TYPE1( ENCRYPTED_SECRET, sizeof(TPMU_ENCRYPTED_SECRET), secret );

/* Table 176  Definition of TPM2_ALG_ID TPMI_ALG_PUBLIC Type */
typedef	TPM2_ALG_ID TPMI_ALG_PUBLIC;

/* Table 177  Definition of TPMU_PUBLIC_ID Union <INOUT S> */
typedef	union {
	TPM2B_DIGEST	keyedHash;	 /*   */
	TPM2B_DIGEST	sym;	 /*   */
	TPM2B_PUBLIC_KEY_RSA	rsa;	 /*   */
	TPMS_ECC_POINT	ecc;	 /*   */
} TPMU_PUBLIC_ID;

/* Table 178  Definition of TPMS_KEYEDHASH_PARMS Structure */
typedef	struct {
	TPMT_KEYEDHASH_SCHEME	scheme;	 /* Indicates the signing method used for a keyedHash signing object. This field also determines the size of the data field for a data object created with TPM2_Create or TPM2_CreatePrimary.  */
} TPMS_KEYEDHASH_PARMS;

/* Table 179  Definition of TPMS_ASYM_PARMS Structure <> */
typedef	struct {
	TPMT_SYM_DEF_OBJECT	symmetric;	 /* the companion symmetric algorithm for a restricted decryption key and shall be set to a supported symmetric algorithmThis field is optional for keys that are not decryption keys and shall be set to TPM2_ALG_NULL if not used.  */
	TPMT_ASYM_SCHEME	scheme;	 /* for a key with the sign attribute SET a valid signing scheme for the key typefor a key with the decrypt attribute SET a valid key exchange protocolfor a key with sign and decrypt attributes shall be TPM2_ALG_NULL  */
} TPMS_ASYM_PARMS;

/* Table 180  Definition of RSA TPMS_RSA_PARMS Structure */
typedef	struct {
	TPMT_SYM_DEF_OBJECT	symmetric;	 /* for a restricted decryption key shall be set to a supported symmetric algorithm key size and mode.if the key is not a restricted decryption key this field shall be set to TPM2_ALG_NULL.  */
	TPMT_RSA_SCHEME	scheme;	 /* scheme.scheme shall befor an unrestricted signing key either TPM2_ALG_RSAPSS TPM2_ALG_RSASSA or TPM2_ALG_NULLfor a restricted signing key either TPM2_ALG_RSAPSS or TPM2_ALG_RSASSAfor an unrestricted decryption key TPM2_ALG_RSAES TPM2_ALG_OAEP or TPM2_ALG_NULL unless the object also has the sign attributefor a restricted decryption key TPM2_ALG_NULLNOTE	When both sign and decrypt are SET restricted shall be CLEAR and scheme shall be TPM2_ALG_NULL.   */
	TPMI_RSA_KEY_BITS	keyBits;	 /* number of bits in the public modulus  */
	UINT32	exponent;	 /* the public exponent A prime number greater than 2.When zero indicates that the exponent is the default of 216 + 1  */
} TPMS_RSA_PARMS;

/* Table 181  Definition of ECC TPMS_ECC_PARMS Structure */
typedef	struct {
	TPMT_SYM_DEF_OBJECT	symmetric;	 /* for a restricted decryption key shall be set to a supported symmetric algorithm key size. and mode.if the key is not a restricted decryption key this field shall be set to TPM2_ALG_NULL.  */
	TPMT_ECC_SCHEME	scheme;	 /* If the sign attribute of the key is SET then this shall be a valid signing scheme.NOTE	If the sign parameter in curveID indicates a mandatory scheme then this field shall have the same value.If the decrypt attribute of the key is SET then this shall be a valid key exchange scheme or TPM2_ALG_NULL.If the key is a Storage Key then this field shall be TPM2_ALG_NULL.   */
	TPMI_ECC_CURVE	curveID;	 /* ECC curve ID  */
	TPMT_KDF_SCHEME	kdf;	 /* an optional key derivation scheme for generating a symmetric key from a Z valueIf the kdf  parameter associated with curveID is not TPM2_ALG_NULL then this is required to be NULL.NOTE	There are currently no commands where this parameter has effect and in the reference code this field needs to be set to TPM2_ALG_NULL.  */
} TPMS_ECC_PARMS;

/* Table 182  Definition of TPMU_PUBLIC_PARMS Union <INOUT S> */
typedef	union {
	TPMS_KEYEDHASH_PARMS	keyedHashDetail;	 /* sign  decrypt  neither  */
	TPMS_SYMCIPHER_PARMS	symDetail;	 /* a symmetric block cipher  */
	TPMS_RSA_PARMS	rsaDetail;	 /* decrypt + sign2  */
	TPMS_ECC_PARMS	eccDetail;	 /* decrypt + sign2  */
	TPMS_ASYM_PARMS	asymDetail;	 /* common scheme structure for RSA and ECC keys  */
} TPMU_PUBLIC_PARMS;

/* Table 183  Definition of TPMT_PUBLIC_PARMS Structure */
typedef	struct {
	TPMI_ALG_PUBLIC	type;	 /* the algorithm to be tested  */
	TPMU_PUBLIC_PARMS	parameters;	 /* the algorithm details  */
} TPMT_PUBLIC_PARMS;

/* Table 184  Definition of TPMT_PUBLIC Structure */
typedef	struct {
	TPMI_ALG_PUBLIC	type;	 /* algorithm associated with this object  */
	TPMI_ALG_HASH	nameAlg;	 /* algorithm used for computing the Name of the objectNOTE	The + indicates that the instance of a TPMT_PUBLIC may have a + to indicate that the nameAlg may be TPM2_ALG_NULL.  */
	TPMA_OBJECT	objectAttributes;	 /* attributes that along with type determine the manipulations of this object  */
	TPM2B_DIGEST	authPolicy;	 /* optional policy for using this keyThe policy is computed using the nameAlg of the object.NOTE 	Shall be the Empty Policy if no authorization policy is present.  */
	TPMU_PUBLIC_PARMS	parameters;	 /* the algorithm or structure details  */
	TPMU_PUBLIC_ID	unique;	 /* the unique identifier of the structureFor an asymmetric key this would be the public key.  */
} TPMT_PUBLIC;

/* Table 185  Definition of TPM2B_PUBLIC Structure */
TPM2B_TYPE2( PUBLIC, TPMT_PUBLIC, publicArea );

/* Table 186  Definition of TPM2B_PRIVATE_VENDOR_SPECIFIC Structure<> */
TPM2B_TYPE1( PRIVATE_VENDOR_SPECIFIC, TPM2_PRIVATE_VENDOR_SPECIFIC_BYTES, buffer );

/* Table 187  Definition of TPMU_SENSITIVE_COMPOSITE Union <INOUT S> */
typedef	union {
	TPM2B_PRIVATE_KEY_RSA	rsa;	 /* a prime factor of the public key  */
	TPM2B_ECC_PARAMETER	ecc;	 /* the integer private key  */
	TPM2B_SENSITIVE_DATA	bits;	 /* the private data  */
	TPM2B_SYM_KEY	sym;	 /* the symmetric key  */
	TPM2B_PRIVATE_VENDOR_SPECIFIC	any;	 /* vendorspecific size for key storage  */
} TPMU_SENSITIVE_COMPOSITE;

/* Table 188  Definition of TPMT_SENSITIVE Structure */
typedef	struct {
	TPMI_ALG_PUBLIC	sensitiveType;	 /* identifier for the sensitive area This shall be the same as the type parameter of the associated public area.  */
	TPM2B_AUTH	authValue;	 /* user authorization dataThe authValue may be a zerolength string.This value shall not be larger than the size of the digest produced by the nameAlg of the object.  */
	TPM2B_DIGEST	seedValue;	 /* for asymmetric key object the optional protection seed for other objects the obfuscation valueThis value shall not be larger than the size of the digest produced by nameAlg of the object.  */
	TPMU_SENSITIVE_COMPOSITE	sensitive;	 /* the typespecific private data  */
} TPMT_SENSITIVE;

/* Table 189  Definition of TPM2B_SENSITIVE Structure <INOUT> */
TPM2B_TYPE2( SENSITIVE, TPMT_SENSITIVE, sensitiveArea );

/* Table 190  Definition of _PRIVATE Structure <> */
typedef	struct {
	TPM2B_DIGEST	integrityOuter;	 /*   */
	TPM2B_DIGEST	integrityInner;	 /* could also be a TPM2B_IV  */
	TPM2B_SENSITIVE	sensitive;	 /* the sensitive area  */
} _PRIVATE;

/* Table 191  Definition of TPM2B_PRIVATE Structure <INOUT S> */
TPM2B_TYPE1( PRIVATE, sizeof(_PRIVATE), buffer );

/* Table 192  Definition of _ID_OBJECT Structure <> */
typedef	struct {
	TPM2B_DIGEST	integrityHMAC;	 /* HMAC using the nameAlg of the storage key on the target TPM  */
	TPM2B_DIGEST	encIdentity;	 /* credential protector information returned if name matches the referenced objectAll of the encIdentity is encrypted including the size field.NOTE	The TPM is not required to check that the size is not larger than the digest of the nameAlg. However if the size is larger the ID object may not be usable on a TPM that has no digest larger than produced by nameAlg.  */
} _ID_OBJECT;

/* Table 193  Definition of TPM2B_ID_OBJECT Structure <INOUT> */
TPM2B_TYPE1( ID_OBJECT, sizeof(_ID_OBJECT), credential );

/* Table 194  Definition of UINT32 TPM2_NV_INDEX Bits <> */
#if defined TPM_BITFIELD_LE

typedef union {
	struct {
	unsigned int index : 24;	/* The Index of the NV location  */
	unsigned int RH_NV : 8;	/* constant value of TPM2_HT_NV_INDEX indicating the NV Index range  */
	};
	UINT32 val;
} TPM2_NV_INDEX;

#elif defined TPM_BITFIELD_BE

typedef union {
	struct {
	unsigned int RH_NV : 8;	/* constant value of TPM2_HT_NV_INDEX indicating the NV Index range  */
	unsigned int index : 24;	/* The Index of the NV location  */
	};
	UINT32 val;
} TPM2_NV_INDEX;

#else

typedef uint32_t	TPM2_NV_INDEX;

#endif

#define TPM2_NV_INDEX_INDEX	0x00FFFFFF
#define TPM2_NV_INDEX_RH_NV	0xFF000000


/* Table 195  Definition of TPM2_NT Constants */
#define	TPM2_NT_ORDINARY	(0x0 )	 /* Ordinary  contains data that is opaque to the TPM that can only be modified using TPM2_NV_Write.  */
#define	TPM2_NT_COUNTER	(0x1 )	 /* Counter  contains an 8octet value that is to be used as a counter and can only be modified with TPM2_NV_Increment  */
#define	TPM2_NT_BITS	(0x2 )	 /* Bit Field  contains an 8octet value to be used as a bit field and can only be modified with TPM2_NV_SetBits.  */
#define	TPM2_NT_EXTEND	(0x4 )	 /* Extend  contains a digestsized value used like a PCR. The Index can only be modified using TPM2_NV_Extend. The extend will use the nameAlg of the Index.  */
#define	TPM2_NT_PIN_FAIL	(0x8 )	 /* PIN Fail  contains a pinCount that increments on a PIN authorization failure and a pinLimit  */
#define	TPM2_NT_PIN_PASS	(0x9 )	 /* PIN Pass  contains a pinCount that increments on a PIN authorization success and a pinLimit  */

/* Table 196  Definition of TPMS_NV_PIN_COUNTER_PARAMETERS Structure */
typedef	struct {
	UINT32	pinCount;	 /* This counter shows the current number of successful authValue authorization attempts to access a TPM2_NT_PIN_PASS index or the current number of unsuccessful authValue authorization attempts to access a TPM2_NT_PIN_FAIL index.  */
	UINT32	pinLimit;	 /* This threshold is the value of pinCount at which the authValue authorization of the host TPM2_NT_PIN_PASS or TPM2_NT_PIN_FAIL index is locked out.  */
} TPMS_NV_PIN_COUNTER_PARAMETERS;

/* Table 197  Definition of UINT32 TPMA_NV Bits */
#if defined TPM_BITFIELD_LE

typedef union {
	struct {
	unsigned int TPMA_NV_PPWRITE : 1;	/* SET 1 The Index data can be written if Platform Authorization is provided.CLEAR 0 Writing of the Index data cannot be authorized with Platform Authorization.  */
	unsigned int TPMA_NV_OWNERWRITE : 1;	/* SET 1 The Index data can be written if Owner Authorization is provided.CLEAR 0 Writing of the Index data cannot be authorized with Owner Authorization.  */
	unsigned int TPMA_NV_AUTHWRITE : 1;	/* SET 1 Authorizations to change the Index contents that require USER role may be provided with an HMAC session or password.CLEAR 0 Authorizations to change the Index contents that require USER role may not be provided with an HMAC session or password.  */
	unsigned int TPMA_NV_POLICYWRITE : 1;	/* SET 1 Authorizations to change the Index contents that require USER role may be provided with a policy session.CLEAR 0 Authorizations to change the Index contents that require USER role may not be provided with a policy session.NOTE	TPM2_NV_ChangeAuth always requires that authorization be provided in a policy session.  */
	unsigned int TPM2_NT : 4;	/* The type of the index. NOTE         A TPM is not required to support all TPM2_NT values  */
	unsigned int reserved1 : 2;	/* shall be zeroreserved for future use  */
	unsigned int TPMA_NV_POLICY_DELETE : 1;	/* SET 1 Index may not be deleted unless the authPolicy is satisfied using TPM2_NV_UndefineSpaceSpecial.CLEAR 0 Index may be deleted with proper platform or owner authorization using TPM2_NV_UndefineSpace.   */
	unsigned int TPMA_NV_WRITELOCKED : 1;	/* SET 1 Index cannot be written.CLEAR 0 Index can be written.  */
	unsigned int TPMA_NV_WRITEALL : 1;	/* SET 1 A partial write of the Index data is not allowed. The write size shall match the defined space size.CLEAR 0 Partial writes are allowed. This setting is required if the .dataSize of the Index is larger than NV_MAX_BUFFER_SIZE for the implementation.  */
	unsigned int TPMA_NV_WRITEDEFINE : 1;	/* SET 1 TPM2_NV_WriteLock may be used to prevent further writes to this location.CLEAR 0 TPM2_NV_WriteLock does not block subsequent writes if TPMA_NV_WRITE_STCLEAR is also CLEAR.  */
	unsigned int TPMA_NV_WRITE_STCLEAR : 1;	/* SET 1 TPM2_NV_WriteLock may be used to prevent further writes to this location until the next TPM Reset or TPM Restart.CLEAR 0 TPM2_NV_WriteLock does not block subsequent writes if TPMA_NV_WRITEDEFINE is also CLEAR.  */
	unsigned int TPMA_NV_GLOBALLOCK : 1;	/* SET 1 If TPM2_NV_GlobalWriteLock is successful then further writes to this location are not permitted until the next TPM Reset or TPM Restart.CLEAR 0 TPM2_NV_GlobalWriteLock has no effect on the writing of the data at this Index.  */
	unsigned int TPMA_NV_PPREAD : 1;	/* SET 1 The Index data can be read if Platform Authorization is provided.CLEAR 0 Reading of the Index data cannot be authorized with Platform Authorization.  */
	unsigned int TPMA_NV_OWNERREAD : 1;	/* SET 1 The Index data can be read if Owner Authorization is provided.CLEAR 0 Reading of the Index data cannot be authorized with Owner Authorization.  */
	unsigned int TPMA_NV_AUTHREAD : 1;	/* SET 1 The Index data may be read if the authValue is provided.CLEAR 0 Reading of the Index data cannot be authorized with the Index authValue.  */
	unsigned int TPMA_NV_POLICYREAD : 1;	/* SET 1 The Index data may be read if the authPolicy is satisfied.CLEAR 0 Reading of the Index data cannot be authorized with the Index authPolicy.  */
	unsigned int reserved2 : 5;	/* shall be zeroreserved for future use   */
	unsigned int TPMA_NV_NO_DA : 1;	/* SET 1 Authorization failures of the Index do not affect the DA logic and authorization of the Index is not blocked when the TPM is in Lockout mode.CLEAR 0 Authorization failures of the Index will increment the authorization failure counter and authorizations of this Index are not allowed when the TPM is in Lockout mode.  */
	unsigned int TPMA_NV_ORDERLY : 1;	/* SET 1 NV Index state is only required to be saved when the TPM performs an orderly shutdown TPM2_Shutdown.CLEAR 0 NV Index state is required to be persistent after the command to update the Index completes successfully that is the NV update is synchronous with the update command.  */
	unsigned int TPMA_NV_CLEAR_STCLEAR : 1;	/* SET 1 TPMA_NV_WRITTEN for the Index is CLEAR by TPM Reset or TPM Restart.CLEAR 0 TPMA_NV_WRITTEN is not changed by TPM Restart.NOTE 1	This attribute may only be SET if TPM2_NT is not TPM2_NT_COUNTER.NOTE 2	If the TPMA_NV_ORDERLY is SET TPMA_NV_WRITTEN will be CLEAR by TPM Reset.  */
	unsigned int TPMA_NV_READLOCKED : 1;	/* SET 1 Reads of the Index are blocked until the next TPM Reset or TPM Restart.CLEAR 0 Reads of the Index are allowed if proper authorization is provided.  */
	unsigned int TPMA_NV_WRITTEN : 1;	/* SET 1 Index has been written.CLEAR 0 Index has not been written.  */
	unsigned int TPMA_NV_PLATFORMCREATE : 1;	/* SET 1 This Index may be undefined with Platform Authorization but not with Owner Authorization.CLEAR 0 This Index may be undefined using Owner Authorization but not with Platform Authorization. The TPM will validate that this attribute is SET when the Index is defined using Platform Authorization and will validate that this attribute is CLEAR when the Index is defined using Owner Authorization.  */
	unsigned int TPMA_NV_READ_STCLEAR : 1;	/* SET 1 TPM2_NV_ReadLock may be used to SET TPMA_NV_READLOCKED for this Index.CLEAR 0 TPM2_NV_ReadLock has no effect on this Index.  */
	};
	UINT32 val;
} TPMA_NV;

#elif defined TPM_BITFIELD_BE

typedef union {
	struct {
	unsigned int TPMA_NV_READ_STCLEAR : 1;	/* SET 1 TPM2_NV_ReadLock may be used to SET TPMA_NV_READLOCKED for this Index.CLEAR 0 TPM2_NV_ReadLock has no effect on this Index.  */
	unsigned int TPMA_NV_PLATFORMCREATE : 1;	/* SET 1 This Index may be undefined with Platform Authorization but not with Owner Authorization.CLEAR 0 This Index may be undefined using Owner Authorization but not with Platform Authorization. The TPM will validate that this attribute is SET when the Index is defined using Platform Authorization and will validate that this attribute is CLEAR when the Index is defined using Owner Authorization.  */
	unsigned int TPMA_NV_WRITTEN : 1;	/* SET 1 Index has been written.CLEAR 0 Index has not been written.  */
	unsigned int TPMA_NV_READLOCKED : 1;	/* SET 1 Reads of the Index are blocked until the next TPM Reset or TPM Restart.CLEAR 0 Reads of the Index are allowed if proper authorization is provided.  */
	unsigned int TPMA_NV_CLEAR_STCLEAR : 1;	/* SET 1 TPMA_NV_WRITTEN for the Index is CLEAR by TPM Reset or TPM Restart.CLEAR 0 TPMA_NV_WRITTEN is not changed by TPM Restart.NOTE 1	This attribute may only be SET if TPM2_NT is not TPM2_NT_COUNTER.NOTE 2	If the TPMA_NV_ORDERLY is SET TPMA_NV_WRITTEN will be CLEAR by TPM Reset.  */
	unsigned int TPMA_NV_ORDERLY : 1;	/* SET 1 NV Index state is only required to be saved when the TPM performs an orderly shutdown TPM2_Shutdown.CLEAR 0 NV Index state is required to be persistent after the command to update the Index completes successfully that is the NV update is synchronous with the update command.  */
	unsigned int TPMA_NV_NO_DA : 1;	/* SET 1 Authorization failures of the Index do not affect the DA logic and authorization of the Index is not blocked when the TPM is in Lockout mode.CLEAR 0 Authorization failures of the Index will increment the authorization failure counter and authorizations of this Index are not allowed when the TPM is in Lockout mode.  */
	unsigned int reserved1 : 5;	/* shall be zeroreserved for future use   */
	unsigned int TPMA_NV_POLICYREAD : 1;	/* SET 1 The Index data may be read if the authPolicy is satisfied.CLEAR 0 Reading of the Index data cannot be authorized with the Index authPolicy.  */
	unsigned int TPMA_NV_AUTHREAD : 1;	/* SET 1 The Index data may be read if the authValue is provided.CLEAR 0 Reading of the Index data cannot be authorized with the Index authValue.  */
	unsigned int TPMA_NV_OWNERREAD : 1;	/* SET 1 The Index data can be read if Owner Authorization is provided.CLEAR 0 Reading of the Index data cannot be authorized with Owner Authorization.  */
	unsigned int TPMA_NV_PPREAD : 1;	/* SET 1 The Index data can be read if Platform Authorization is provided.CLEAR 0 Reading of the Index data cannot be authorized with Platform Authorization.  */
	unsigned int TPMA_NV_GLOBALLOCK : 1;	/* SET 1 If TPM2_NV_GlobalWriteLock is successful then further writes to this location are not permitted until the next TPM Reset or TPM Restart.CLEAR 0 TPM2_NV_GlobalWriteLock has no effect on the writing of the data at this Index.  */
	unsigned int TPMA_NV_WRITE_STCLEAR : 1;	/* SET 1 TPM2_NV_WriteLock may be used to prevent further writes to this location until the next TPM Reset or TPM Restart.CLEAR 0 TPM2_NV_WriteLock does not block subsequent writes if TPMA_NV_WRITEDEFINE is also CLEAR.  */
	unsigned int TPMA_NV_WRITEDEFINE : 1;	/* SET 1 TPM2_NV_WriteLock may be used to prevent further writes to this location.CLEAR 0 TPM2_NV_WriteLock does not block subsequent writes if TPMA_NV_WRITE_STCLEAR is also CLEAR.  */
	unsigned int TPMA_NV_WRITEALL : 1;	/* SET 1 A partial write of the Index data is not allowed. The write size shall match the defined space size.CLEAR 0 Partial writes are allowed. This setting is required if the .dataSize of the Index is larger than NV_MAX_BUFFER_SIZE for the implementation.  */
	unsigned int TPMA_NV_WRITELOCKED : 1;	/* SET 1 Index cannot be written.CLEAR 0 Index can be written.  */
	unsigned int TPMA_NV_POLICY_DELETE : 1;	/* SET 1 Index may not be deleted unless the authPolicy is satisfied using TPM2_NV_UndefineSpaceSpecial.CLEAR 0 Index may be deleted with proper platform or owner authorization using TPM2_NV_UndefineSpace.   */
	unsigned int reserved2 : 2;	/* shall be zeroreserved for future use  */
	unsigned int TPM2_NT : 4;	/* The type of the index. NOTE         A TPM is not required to support all TPM2_NT values  */
	unsigned int TPMA_NV_POLICYWRITE : 1;	/* SET 1 Authorizations to change the Index contents that require USER role may be provided with a policy session.CLEAR 0 Authorizations to change the Index contents that require USER role may not be provided with a policy session.NOTE	TPM2_NV_ChangeAuth always requires that authorization be provided in a policy session.  */
	unsigned int TPMA_NV_AUTHWRITE : 1;	/* SET 1 Authorizations to change the Index contents that require USER role may be provided with an HMAC session or password.CLEAR 0 Authorizations to change the Index contents that require USER role may not be provided with an HMAC session or password.  */
	unsigned int TPMA_NV_OWNERWRITE : 1;	/* SET 1 The Index data can be written if Owner Authorization is provided.CLEAR 0 Writing of the Index data cannot be authorized with Owner Authorization.  */
	unsigned int TPMA_NV_PPWRITE : 1;	/* SET 1 The Index data can be written if Platform Authorization is provided.CLEAR 0 Writing of the Index data cannot be authorized with Platform Authorization.  */
	};
	UINT32 val;
} TPMA_NV;

#else

typedef uint32_t	TPMA_NV;

#endif

#define TPMA_NV_TPMA_NV_PPWRITE	0x00000001
#define TPMA_NV_TPMA_NV_OWNERWRITE	0x00000002
#define TPMA_NV_TPMA_NV_AUTHWRITE	0x00000004
#define TPMA_NV_TPMA_NV_POLICYWRITE	0x00000008
#define TPMA_NV_TPM2_NT	0x000000F0
#define TPMA_NV_RESERVED1	0x00000300
#define TPMA_NV_TPMA_NV_POLICY_DELETE	0x00000400
#define TPMA_NV_TPMA_NV_WRITELOCKED	0x00000800
#define TPMA_NV_TPMA_NV_WRITEALL	0x00001000
#define TPMA_NV_TPMA_NV_WRITEDEFINE	0x00002000
#define TPMA_NV_TPMA_NV_WRITE_STCLEAR	0x00004000
#define TPMA_NV_TPMA_NV_GLOBALLOCK	0x00008000
#define TPMA_NV_TPMA_NV_PPREAD	0x00010000
#define TPMA_NV_TPMA_NV_OWNERREAD	0x00020000
#define TPMA_NV_TPMA_NV_AUTHREAD	0x00040000
#define TPMA_NV_TPMA_NV_POLICYREAD	0x00080000
#define TPMA_NV_RESERVED2	0x01F00000
#define TPMA_NV_TPMA_NV_NO_DA	0x02000000
#define TPMA_NV_TPMA_NV_ORDERLY	0x04000000
#define TPMA_NV_TPMA_NV_CLEAR_STCLEAR	0x08000000
#define TPMA_NV_TPMA_NV_READLOCKED	0x10000000
#define TPMA_NV_TPMA_NV_WRITTEN	0x20000000
#define TPMA_NV_TPMA_NV_PLATFORMCREATE	0x40000000
#define TPMA_NV_TPMA_NV_READ_STCLEAR	0x80000000


/* Table 198  Definition of TPMS_NV_PUBLIC Structure */
typedef	struct {
	TPMI_RH_NV_INDEX	nvIndex;	 /* the handle of the data area  */
	TPMI_ALG_HASH	nameAlg;	 /* hash algorithm used to compute the name of the Index and used for the authPolicy.  For an extend index the hash algorithm used for the extend.  */
	TPMA_NV	attributes;	 /* the Index attributes  */
	TPM2B_DIGEST	authPolicy;	 /* optional access policy for the Index The policy is computed using the nameAlg NOTE 	Shall be the Empty Policy if no authorization 	policy is present.  */
	UINT16	dataSize;	 /* the size of the data areaThe maximum size is implementationdependent. The minimum maximum size is platformspecific.  */
} TPMS_NV_PUBLIC;

/* Table 199  Definition of TPM2B_NV_PUBLIC Structure */
TPM2B_TYPE2( NV_PUBLIC, TPMS_NV_PUBLIC, nvPublic );

/* Table 200  Definition of TPM2B_CONTEXT_SENSITIVE Structure <INOUT> */
TPM2B_TYPE1( CONTEXT_SENSITIVE, TPM2_MAX_CONTEXT_SIZE, buffer );

/* Table 201  Definition of TPMS_CONTEXT_DATA Structure <INOUT S> */
typedef	struct {
	TPM2B_DIGEST	integrity;	 /* the integrity value  */
	TPM2B_CONTEXT_SENSITIVE	encrypted;	 /* the sensitive area  */
} TPMS_CONTEXT_DATA;

/* Table 202  Definition of TPM2B_CONTEXT_DATA Structure <INOUT> */
TPM2B_TYPE1( CONTEXT_DATA, sizeof(TPMS_CONTEXT_DATA), buffer );

/* Table 203  Definition of TPMS_CONTEXT Structure */
typedef	struct {
	UINT64	sequence;	 /* the sequence number of the contextNOTE	Transient object contexts and session contexts used different counters.  */
	TPMI_DH_CONTEXT	savedHandle;	 /* a handle indicating if the context is a session object or sequence objectSee Table 204  Context Handle Values  */
	TPMI_RH_HIERARCHY	hierarchy;	 /* the hierarchy of the context  */
	TPM2B_CONTEXT_DATA	contextBlob;	 /* the context data and integrity HMAC  */
} TPMS_CONTEXT;

/* Table 205  Definition of TPMS_CREATION_DATA Structure <OUT> */
typedef	struct {
	TPML_PCR_SELECTION	pcrSelect;	 /* list indicating the PCR included in pcrDigest  */
	TPM2B_DIGEST	pcrDigest;	 /* digest of the selected PCR using nameAlg of the object for which this structure is being createdpcrDigest.size shall be zero if the pcrSelect list is empty.  */
	TPMA_LOCALITY	locality;	 /* the locality at which the object was created  */
	TPM2_ALG_ID	parentNameAlg;	 /* nameAlg of the parent  */
	TPM2B_NAME	parentName;	 /* Name of the parent at time of creationThe size will match digest size associated with parentNameAlg unless it is TPM2_ALG_NULL in which case the size will be 4 and parentName will be the hierarchy handle.  */
	TPM2B_NAME	parentQualifiedName;	 /* Qualified Name of the parent at the time of creationSize is the same as parentName.  */
	TPM2B_DATA	outsideInfo;	 /* association with additional information added by the key creatorThis will be the contents of the outsideInfo parameter in TPM2_Create or TPM2_CreatePrimary.  */
} TPMS_CREATION_DATA;

/* Table 206  Definition of TPM2B_CREATION_DATA Structure <OUT> */
TPM2B_TYPE2( CREATION_DATA, TPMS_CREATION_DATA, creationData );

typedef UINT32 TPM_AT;

/* Definition of (UINT32) TPM_AT Constants.
 * Note: values of 0x80000000 through 0xFFFFFFFF are reserved for vendor-specific use */
#define TPM_AT_ANY   0x00000000 /* In a command, a non-specific request for AC information. In a response, indicates that outputData is not meaningful */
#define TPM_AT_ERROR 0x00000001 /* Indicates a TCG defined, device-specific error */
#define TPM_AT_PV1   0x00000002 /* Indicates the most significant 32 bits of a pairing value for the AC */
#define TPM_AT_VEND  0x80000000 /* Value added to a TPM_AT to indicate a vendor-specific tag value */

typedef UINT32 TPM_EA;

#define TPM_AE_NONE  0x00000000 /* In a command, a non-specific request for AC information. In a response, indicates that outputData is not meaningful */

typedef TPM2_HANDLE TPMI_RH_AC; /* Interface used to identify an attached component */

/* Definition of TPMS_AC_OUTPUT Structure <OUT> */
typedef struct {
    TPM_AT tag; /* Indicates the contents of data */
    UINT32 data; /* Data returned from the AC */
} TPMS_AC_OUTPUT;

/* Definition of TPML_AC_CAPABILITIES Structure <OUT> */
typedef struct {
    UINT32 count; /* Number of values in the acCapabilities list. May be 0 */
    TPMS_AC_OUTPUT acCapabilities[TPM2_MAX_AC_CAPABILITIES]; /* List of AC values */
} TPML_AC_CAPABILITIES;
#endif
