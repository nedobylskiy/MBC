/*
?? MP3 ?? ID3V1?ID3V2 ?? 
??????????,????????MP3???TAG??????????,????????????????

???ID3??????????,????? www.id3.org(E???,E???????? www.google.com ??http://www.google.com/search?hl=zh-CN&q=%E4%BB%80%E4%B9%88%E6%98%AFID3&lr=lang_zh-CN 

 

??????? VC6 ????????,?????????????,???,???C?????,????????

 

1?  ?????????.h?.c,??:???????,???C??????

2?  ??????????API??,??HFILE, ReadFile(..)?,???????,?????? J

3?  ?????,?????????,??????
*/
 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///  .h ??


/********************************************************************

  ????: ??Audio???????????MP3??ID3V1??

  ????: audioInfo.h

  ???  : 1.0.0

  ????:       2005-10-24   9:11

  ?    ?: hengai

  ????: 

      2005-10-24 17:30: ??? ID3V2 ?TAG????????? #define ??? static LPCTSTR

      2005-10-24 18:10: ???? MP3 ????ID3V2???

          ????????? MP3ID3V2INFO ???????????????(??????????)

*********************************************************************/ 

 

#define AUDIO_OUT_ERRMSG        //??????????

//////////////////////////////////////////////////////////////////////////

//???? MP3 ID3V1 ???????

//MP3 ID3V1 ?????MP3?????128????

typedef struct tag_MP3ID3V1INFO      //MP3?????ShitMP3v1.07

{

  TCHAR   Identify[3];     //TAG??????????????????????

  TCHAR   Title[30];       //???,30???

  TCHAR   Artist[30];      //???,30???

  TCHAR   Album[30];       //????,30???

  TCHAR   Year[4];         //?,4???

  TCHAR   Comment[28];     //??,???28???(???30???,????????2???)

  UCHAR   CommentFlag;     //???1,??????????? 0x00 ???????28,???30

  UCHAR   Track;           //???2,??“???”,????

  UCHAR   Genre;           //???3,????,?0-148?????Pop,General...

  TCHAR   pszGenre[30];    //?????????

 //

 BOOL   bHasTag;         //?? MP3 ???? ID3V1 TAG??

} MP3ID3V1INFO, *PMP3ID3V1INFO;

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//MP3 ID3V2 FrameID

enum ID3_FrameID{

  /* ???? */ ID3FID_NOFRAME = 0,       /**< No known frame */

  /* AENC */ ID3FID_AUDIOCRYPTO,       /**< Audio encryption */

  /* APIC */ ID3FID_PICTURE,           /**< Attached picture */

  /* ASPI */ ID3FID_AUDIOSEEKPOINT,    /**< Audio seek point index */

  /* COMM */ ID3FID_COMMENT,           /**< Comments */

  /* COMR */ ID3FID_COMMERCIAL,        /**< Commercial frame */

  /* ENCR */ ID3FID_CRYPTOREG,         /**< Encryption method registration */

  /* EQU2 */ ID3FID_EQUALIZATION2,     /**< Equalisation (2) */

  /* EQUA */ ID3FID_EQUALIZATION,      /**< Equalization */

  /* ETCO */ ID3FID_EVENTTIMING,       /**< Event timing codes */

  /* GEOB */ ID3FID_GENERALOBJECT,     /**< General encapsulated object */

  /* GRID */ ID3FID_GROUPINGREG,       /**< Group identification registration */

  /* IPLS */ ID3FID_INVOLVEDPEOPLE,    /**< Involved people list */

  /* LINK */ ID3FID_LINKEDINFO,        /**< Linked information */

  /* MCDI */ ID3FID_CDID,              /**< Music CD identifier */

  /* MLLT */ ID3FID_MPEGLOOKUP,        /**< MPEG location lookup table */

  /* OWNE */ ID3FID_OWNERSHIP,         /**< Ownership frame */

  /* PRIV */ ID3FID_PRIVATE,           /**< Private frame */

  /* PCNT */ ID3FID_PLAYCOUNTER,       /**< Play counter */

  /* POPM */ ID3FID_POPULARIMETER,     /**< Popularimeter */

  /* POSS */ ID3FID_POSITIONSYNC,      /**< Position synchronisation frame */

  /* RBUF */ ID3FID_BUFFERSIZE,        /**< Recommended buffer size */

  /* RVA2 */ ID3FID_VOLUMEADJ2,        /**< Relative volume adjustment (2) */

  /* RVAD */ ID3FID_VOLUMEADJ,         /**< Relative volume adjustment */

  /* RVRB */ ID3FID_REVERB,            /**< Reverb */

  /* SEEK */ ID3FID_SEEKFRAME,         /**< Seek frame */

  /* SIGN */ ID3FID_SIGNATURE,         /**< Signature frame */

  /* SYLT */ ID3FID_SYNCEDLYRICS,      /**< Synchronized lyric/text */

  /* SYTC */ ID3FID_SYNCEDTEMPO,       /**< Synchronized tempo codes */

  /* TALB */ ID3FID_ALBUM,             /**< Album/Movie/Show title */

  /* TBPM */ ID3FID_BPM,               /**< BPM (beats per minute) */

  /* TCOM */ ID3FID_COMPOSER,          /**< Composer */

  /* TCON */ ID3FID_CONTENTTYPE,       /**< Content type */

  /* TCOP */ ID3FID_COPYRIGHT,         /**< Copyright message */

  /* TDAT */ ID3FID_DATE,              /**< Date */

  /* TDEN */ ID3FID_ENCODINGTIME,      /**< Encoding time */

  /* TDLY */ ID3FID_PLAYLISTDELAY,     /**< Playlist delay */

  /* TDOR */ ID3FID_ORIGRELEASETIME,   /**< Original release time */

  /* TDRC */ ID3FID_RECORDINGTIME,     /**< Recording time */

  /* TDRL */ ID3FID_RELEASETIME,       /**< Release time */

  /* TDTG */ ID3FID_TAGGINGTIME,       /**< Tagging time */

  /* TIPL */ ID3FID_INVOLVEDPEOPLE2,   /**< Involved people list */

  /* TENC */ ID3FID_ENCODEDBY,         /**< Encoded by */

  /* TEXT */ ID3FID_LYRICIST,          /**< Lyricist/Text writer */

  /* TFLT */ ID3FID_FILETYPE,          /**< File type */

  /* TIME */ ID3FID_TIME,              /**< Time */

  /* TIT1 */ ID3FID_CONTENTGROUP,      /**< Content group description */

  /* TIT2 */ ID3FID_TITLE,             /**< Title/songname/content description */

  /* TIT3 */ ID3FID_SUBTITLE,          /**< Subtitle/Description refinement */

  /* TKEY */ ID3FID_INITIALKEY,        /**< Initial key */

  /* TLAN */ ID3FID_LANGUAGE,          /**< Language(s) */

  /* TLEN */ ID3FID_SONGLEN,           /**< Length */

  /* TMCL */ ID3FID_MUSICIANCREDITLIST,/**< Musician credits list */

  /* TMED */ ID3FID_MEDIATYPE,         /**< Media type */

  /* TMOO */ ID3FID_MOOD,              /**< Mood */

  /* TOAL */ ID3FID_ORIGALBUM,         /**< Original album/movie/show title */

  /* TOFN */ ID3FID_ORIGFILENAME,      /**< Original filename */

  /* TOLY */ ID3FID_ORIGLYRICIST,      /**< Original lyricist(s)/text writer(s) */

  /* TOPE */ ID3FID_ORIGARTIST,        /**< Original artist(s)/performer(s) */

  /* TORY */ ID3FID_ORIGYEAR,          /**< Original release year */

  /* TOWN */ ID3FID_FILEOWNER,         /**< File owner/licensee */

  /* TPE1 */ ID3FID_LEADARTIST,        /**< Lead performer(s)/Soloist(s) */

  /* TPE2 */ ID3FID_BAND,              /**< Band/orchestra/accompaniment */

  /* TPE3 */ ID3FID_CONDUCTOR,         /**< Conductor/performer refinement */

  /* TPE4 */ ID3FID_MIXARTIST,         /**< Interpreted, remixed, or otherwise modified by */

  /* TPOS */ ID3FID_PARTINSET,         /**< Part of a set */

  /* TPRO */ ID3FID_PRODUCEDNOTICE,    /**< Produced notice */

  /* TPUB */ ID3FID_PUBLISHER,         /**< Publisher */

  /* TRCK */ ID3FID_TRACKNUM,          /**< Track number/Position in set */

  /* TRDA */ ID3FID_RECORDINGDATES,    /**< Recording dates */

  /* TRSN */ ID3FID_NETRADIOSTATION,   /**< Internet radio station name */

  /* TRSO */ ID3FID_NETRADIOOWNER,     /**< Internet radio station owner */

  /* TSIZ */ ID3FID_SIZE,              /**< Size */

  /* TSOA */ ID3FID_ALBUMSORTORDER,    /**< Album sort order */

  /* TSOP */ ID3FID_PERFORMERSORTORDER,/**< Performer sort order */

  /* TSOT */ ID3FID_TITLESORTORDER,    /**< Title sort order */

  /* TSRC */ ID3FID_ISRC,              /**< ISRC (international standard recording code) */

  /* TSSE */ ID3FID_ENCODERSETTINGS,   /**< Software/Hardware and settings used for encoding */

  /* TSST */ ID3FID_SETSUBTITLE,       /**< Set subtitle */

  /* TXXX */ ID3FID_USERTEXT,          /**< User defined text information */

  /* TYER */ ID3FID_YEAR,              /**< Year */

  /* UFID */ ID3FID_UNIQUEFILEID,      /**< Unique file identifier */

  /* USER */ ID3FID_TERMSOFUSE,        /**< Terms of use */

  /* USLT */ ID3FID_UNSYNCEDLYRICS,    /**< Unsynchronized lyric/text transcription */

  /* WCOM */ ID3FID_WWWCOMMERCIALINFO, /**< Commercial information */

  /* WCOP */ ID3FID_WWWCOPYRIGHT,      /**< Copyright/Legal infromation */

  /* WOAF */ ID3FID_WWWAUDIOFILE,      /**< Official audio file webpage */

  /* WOAR */ ID3FID_WWWARTIST,         /**< Official artist/performer webpage */

  /* WOAS */ ID3FID_WWWAUDIOSOURCE,    /**< Official audio source webpage */

  /* WORS */ ID3FID_WWWRADIOPAGE,      /**< Official internet radio station homepage */

  /* WPAY */ ID3FID_WWWPAYMENT,        /**< Payment */

  /* WPUB */ ID3FID_WWWPUBLISHER,      /**< Official publisher webpage */

  /* WXXX */ ID3FID_WWWUSER,           /**< User defined URL link */

  /*      */ ID3FID_METACRYPTO,        /**< Encrypted meta frame (id3v2.2.x) */

  /*      */ ID3FID_METACOMPRESSION,   /**< Compressed meta frame (id3v2.2.1) */

  /* >>>> */ ID3FID_LASTFRAMEID,       /**< Last field placeholder */

  ID3FID_MAX_COUNT,

};

////???? MP3 ID3V2 ???????

typedef struct tag_MP3ID3V2INFO

{

  TCHAR   Identify[3];    //ID3??????????????????????

  struct

  {

    UCHAR majorversion;   //????

    UCHAR revision;       //????

  }       Version;

  UCHAR   HeaderFlags;

  UCHAR   HeaderSize[4];  //Note:?byte??????0x80,??size????bit 7??0

  //?????,? 10 ???,?? ID3V2 ????

  BOOL    bHasExtHeader;  //? ID3V2 ???????????

  BOOL    bHasExtFooter;  //? ID3V2 ???????????

  DWORD   dwInfoSize;     //ID3V2 ?????

  LPSTR   ppszTagInfo[ID3FID_MAX_COUNT];  //???? Tag ????????ppszTagInfo[]!=NULL

      //??: ???? Comment ??,?????4????,?????LPCSTR pszComment = (LPCTSTR)&ppszTagInfo[ID3FID_COMMENT][4];

      //????:eng\0???,???????4???

  BOOL    bHasTag;        //?? MP3 ????? ID3V2 ??

}MP3ID3V2INFO, *PMP3ID3V2INFO;

 

//////////////////////////////////////////////////////////////////////////

#ifndef STATIC

#define STATIC  static

#endif

////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//

//              ??????????

//

//////////////////////////////////////////////////////////////////////////

LPCTSTR Audio_GetErrorString();                       //??????

 

/*********************************************************************

  ????: int AudioInfo_GetMP3ID3V1(HFILE hAudioFile, MP3ID3V1INFO *pMp3ID3V1Info)

  ?    ?:

          IN: HFILE hMP3File: ??????? MP3 ??

              MP3ID3V1INFO *pMp3ID3V1Info: ??? MP3  ??????????

         OUT: 

         I/O: 

    ???: ????>=0,????<0????????? Audio_GetErrorString ??????? 

            ??? MP3 ????? ID3V1,?? bHasTag == TRUE

  ????: ?? MP3 ?? ID3V1 ??

  ?    ?: 

*********************************************************************/

int AudioInfo_GetMP3ID3V1(HFILE hMP3File, MP3ID3V1INFO *pMP3ID3V1Info);

 

/*********************************************************************

  ????: int AudioInfo_GetMP3ID3V2(HFILE hMP3File, MP3ID3V2INFO *pMP3ID3V2Info)

  ?    ?:

          IN: HFILE hMP3File: ??????? MP3 ??

              MP3ID3V2INFO *pMp3ID3V2Info: ??? MP3  ??????????

         OUT: 

         I/O: 

    ???: ????>=0,????<0????????? Audio_GetErrorString ???????

            ??? MP3 ????? ID3V2,?? bHasTag == TRUE

  ????: ?? MP3 ?? ID3V2 ??

      ??: ??ID3V2?????,????? AudioInfo_MP3ID3V2Free(MP3ID3V2INFO *pMP3ID3V2Info)

  ?    ?: 

*********************************************************************/

int AudioInfo_GetMP3ID3V2(HFILE hMP3File, MP3ID3V2INFO *pMP3ID3V2Info);

 

/*********************************************************************

  ????: VOID AudioInfo_MP3ID3V2Free(MP3ID3V2INFO *pMP3ID3V2Info)

  ?    ?:

          IN: MP3ID3V2INFO *pMP3ID3V2Info: ????????

         OUT: 

         I/O: 

    ???: 

  ????: ?? MP3ID3V2INFO ????,????

  ?    ?: 

*********************************************************************/

VOID AudioInfo_MP3ID3V2Free(MP3ID3V2INFO *pMP3ID3V2Info);

 



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///  .c ??


/********************************************************************

  ????: ??Audio???????????MP3??ID3V1??

  ????: audioInfo.c

  ???  : 1.0.0

  ????:   2005-10-24   9:11

  ?    ?: hengai

  ????: 

  ????: 

      2005-10-24 17:30: ??? ID3V2 ?TAG????????? #define ??? static LPCTSTR

      2005-10-24 18:10: ???? MP3 ????ID3V2???

          ????????? MP3ID3V2INFO ???????????????(??????????)

        ????? AudioInfo_GetFrameHeader(..)???????? ID3V2 ??

        ????? AudioInfo_MP3ID3V2Free(..)??????????

*********************************************************************/

#include "audioInfo.h"

 

#ifdef AUDIO_OUT_ERRMSG

STATIC TCHAR m_szLastError[256];  //??????????

#define AUDIO_ERR_OUT(str_err) strcpy(m_szLastError,str_err);

LPCTSTR Audio_GetErrorString()

{

  return (LPCTSTR)m_szLastError;

}

#else

#define AUDIO_ERR_OUT

LPCTSTR Audio_GetErrorString()

{

  return "Plese #define AUDIO_OUT_ERRMSG in audioInfo.h";

}

#endif

//?? MP3 ???????

STATIC int m_nMP3ID3v2GenreCount = 148;

STATIC LPCTSTR m_arrMP3ID3v2Genre[] = {

    "Blues","Classic Rock","Country","Dance","Disco","Funk","Grunge","Hip-Hop",

    "Jazz","Metal","New Age","Oldies","Other","Pop","R&B","Rap","Reggae","Rock",

    "Techno","Industrial","Alternative","Ska","Death Metal","Pranks","Soundtrack",

    "Euro-Techno","Ambient","Trip Hop","Vocal","Jazz Funk","Fusion","Trance",

    "Classical","Instrumental","Acid","House","Game","Sound Clip","Gospel","Noise",

    "Alternative Rock","Bass","Soul","Punk","Space","Meditative","Instrumental Pop",

    "Instrumental Rock","Ethnic","Gothic","Darkwave","Techno-Industrial","Electronic",

    "Pop Folk","Eurodance","Dream","Southern Rock","Comedy","Cult","Gangsta","Top 40",

    "Christian Rap","Pop Funk","Jungle","Native American","Cabaret","New Wave",

    "Psychadelic","Rave","ShowTunes","Trailer","Lo-Fi","Tribal","Acid Punk","Acid Jazz",

    "Polka","Retro","Musical","Rock & Roll","Hard Rock","Folk","Folk Rock",

    "National Folk","Swing","Fast Fusion","Bebob","Latin","Revival","Celtic",

    "Bluegrass","Avantgarde","Gothic Rock","Progressive Rock","Psychedelic Rock",

    "Symphonic Rock","Slow Rock","Big Band","Chorus","Easy Listening","Acoustic",

    "Humour","Speech","Chanson","Opera","Chamber Music","Sonata","Symphony","Booty Bass",

    "Primus","Porn Groove","Satire","Slow Jam","Club","Tango","Samba","Folklore","Ballad",

    "Power Ballad","Rhytmic Soul","Freestyle","Duet","Punk Rock","Drum Solo","A Capella",

    "Euro House","Dance Hall","Goa","Drum & Bass","Club House","Hardcore","Terror",

    "Indie","BritPop","Negerpunk","Polsk Punk","Beat","Christian Gangsta Rap",

    "Heavy Metal","Black Metal","Crossover","Contemporary Christian","Christian Rock",

    "Merengue","Salsa","Trash Metal","Anime","JPop","SynthPop"

};

//???????????

//define frame id (see in ID3v2.3)

//#define ID3V2_FRAMEID_TITLE     "TIT2"    //Title

//#define ID3V2_FRAMEID_ARTIST    "TPE1"    //Artist

//#define ID3V2_FRAMEID_ALBUM     "TALB"    //Album

//#define ID3V2_FRAMEID_TRACK     "TRCK"    //Track

//#define ID3V2_FRAMEID_YEAR      "TYER"    //Year

//#define ID3V2_FRAMEID_COMMENT   "COMM"    //Comment

//#define ID3V2_FRAMEID_GENRE     "TCON"    //Genre

//#define ID3V2_FRAMEID_ENCODEBY  "TENC"    //Encode By(????)

//#define ID3V2_FRAMEID_COPYRIGHT "TCOP"    //Copyright

//#define  ID3V2_FRAMEID_URL       "WXXX"    //URL

 

STATIC LPCTSTR m_pszID3V2FrameId[] = 

{

  "????", /* ID3FID_NOFRAME = 0,        */ /**< No known frame */

  "AENC", /* ID3FID_AUDIOCRYPTO,        */ /**< Audio encryption */

  "APIC", /* ID3FID_PICTURE,            */ /**< Attached picture */

  "ASPI", /* ID3FID_AUDIOSEEKPOINT,     */ /**< Audio seek point index */

  "COMM", /* ID3FID_COMMENT,            */ /**< Comments */

  "COMR", /* ID3FID_COMMERCIAL,         */ /**< Commercial frame */

  "ENCR", /* ID3FID_CRYPTOREG,          */ /**< Encryption method registration */

  "EQU2", /* ID3FID_EQUALIZATION2,      */ /**< Equalisation (2) */

  "EQUA", /* ID3FID_EQUALIZATION,       */ /**< Equalization */

  "ETCO", /* ID3FID_EVENTTIMING,        */ /**< Event timing codes */

  "GEOB", /* ID3FID_GENERALOBJECT,      */ /**< General encapsulated object */

  "GRID", /* ID3FID_GROUPINGREG,        */ /**< Group identification registration */

  "IPLS", /* ID3FID_INVOLVEDPEOPLE,     */ /**< Involved people list */

  "LINK", /* ID3FID_LINKEDINFO,         */ /**< Linked information */

  "MCDI", /* ID3FID_CDID,               */ /**< Music CD identifier */

  "MLLT", /* ID3FID_MPEGLOOKUP,         */ /**< MPEG location lookup table */

  "OWNE", /* ID3FID_OWNERSHIP,          */ /**< Ownership frame */

  "PRIV", /* ID3FID_PRIVATE,            */ /**< Private frame */

  "PCNT", /* ID3FID_PLAYCOUNTER,        */ /**< Play counter */

  "POPM", /* ID3FID_POPULARIMETER,      */ /**< Popularimeter */

  "POSS", /* ID3FID_POSITIONSYNC,       */ /**< Position synchronisation frame */

  "RBUF", /* ID3FID_BUFFERSIZE,         */ /**< Recommended buffer size */

  "RVA2", /* ID3FID_VOLUMEADJ2,         */ /**< Relative volume adjustment (2) */

  "RVAD", /* ID3FID_VOLUMEADJ,          */ /**< Relative volume adjustment */

  "RVRB", /* ID3FID_REVERB,             */ /**< Reverb */

  "SEEK", /* ID3FID_SEEKFRAME,          */ /**< Seek frame */

  "SIGN", /* ID3FID_SIGNATURE,          */ /**< Signature frame */

  "SYLT", /* ID3FID_SYNCEDLYRICS,       */ /**< Synchronized lyric/text */

  "SYTC", /* ID3FID_SYNCEDTEMPO,        */ /**< Synchronized tempo codes */

  "TALB", /* ID3FID_ALBUM,              */ /**< Album/Movie/Show title */

  "TBPM", /* ID3FID_BPM,                */ /**< BPM (beats per minute) */

  "TCOM", /* ID3FID_COMPOSER,           */ /**< Composer */

  "TCON", /* ID3FID_CONTENTTYPE,        */ /**< Content type */

  "TCOP", /* ID3FID_COPYRIGHT,          */ /**< Copyright message */

  "TDAT", /* ID3FID_DATE,               */ /**< Date */

  "TDEN", /* ID3FID_ENCODINGTIME,       */ /**< Encoding time */

  "TDLY", /* ID3FID_PLAYLISTDELAY,      */ /**< Playlist delay */

  "TDOR", /* ID3FID_ORIGRELEASETIME,    */ /**< Original release time */

  "TDRC", /* ID3FID_RECORDINGTIME,      */ /**< Recording time */

  "TDRL", /* ID3FID_RELEASETIME,        */ /**< Release time */

  "TDTG", /* ID3FID_TAGGINGTIME,        */ /**< Tagging time */

  "TIPL", /* ID3FID_INVOLVEDPEOPLE2,    */ /**< Involved people list */

  "TENC", /* ID3FID_ENCODEDBY,          */ /**< Encoded by */

  "TEXT", /* ID3FID_LYRICIST,           */ /**< Lyricist/Text writer */

  "TFLT", /* ID3FID_FILETYPE,           */ /**< File type */

  "TIME", /* ID3FID_TIME,               */ /**< Time */

  "TIT1", /* ID3FID_CONTENTGROUP,       */ /**< Content group description */

  "TIT2", /* ID3FID_TITLE,              */ /**< Title/songname/content description */

  "TIT3", /* ID3FID_SUBTITLE,           */ /**< Subtitle/Description refinement */

  "TKEY", /* ID3FID_INITIALKEY,         */ /**< Initial key */

  "TLAN", /* ID3FID_LANGUAGE,           */ /**< Language(s) */

  "TLEN", /* ID3FID_SONGLEN,            */ /**< Length */

  "TMCL", /* ID3FID_MUSICIANCREDITLIST, */ /**< Musician credits list */

  "TMED", /* ID3FID_MEDIATYPE,          */ /**< Media type */

  "TMOO", /* ID3FID_MOOD,               */ /**< Mood */

  "TOAL", /* ID3FID_ORIGALBUM,          */ /**< Original album/movie/show title */

  "TOFN", /* ID3FID_ORIGFILENAME,       */ /**< Original filename */

  "TOLY", /* ID3FID_ORIGLYRICIST,       */ /**< Original lyricist(s)/text writer(s) */

  "TOPE", /* ID3FID_ORIGARTIST,         */ /**< Original artist(s)/performer(s) */

  "TORY", /* ID3FID_ORIGYEAR,           */ /**< Original release year */

  "TOWN", /* ID3FID_FILEOWNER,          */ /**< File owner/licensee */

  "TPE1", /* ID3FID_LEADARTIST,         */ /**< Lead performer(s)/Soloist(s) */

  "TPE2", /* ID3FID_BAND,               */ /**< Band/orchestra/accompaniment */

  "TPE3", /* ID3FID_CONDUCTOR,          */ /**< Conductor/performer refinement */

  "TPE4", /* ID3FID_MIXARTIST,          */ /**< Interpreted, remixed, or otherwise modified by */

  "TPOS", /* ID3FID_PARTINSET,          */ /**< Part of a set */

  "TPRO", /* ID3FID_PRODUCEDNOTICE,     */ /**< Produced notice */

  "TPUB", /* ID3FID_PUBLISHER,          */ /**< Publisher */

  "TRCK", /* ID3FID_TRACKNUM,           */ /**< Track number/Position in set */

  "TRDA", /* ID3FID_RECORDINGDATES,     */ /**< Recording dates */

  "TRSN", /* ID3FID_NETRADIOSTATION,    */ /**< Internet radio station name */

  "TRSO", /* ID3FID_NETRADIOOWNER,      */ /**< Internet radio station owner */

  "TSIZ", /* ID3FID_SIZE,               */ /**< Size */

  "TSOA", /* ID3FID_ALBUMSORTORDER,     */ /**< Album sort order */

  "TSOP", /* ID3FID_PERFORMERSORTORDER, */ /**< Performer sort order */

  "TSOT", /* ID3FID_TITLESORTORDER,     */ /**< Title sort order */

  "TSRC", /* ID3FID_ISRC,               */ /**< ISRC (international standard recording code) */

  "TSSE", /* ID3FID_ENCODERSETTINGS,    */ /**< Software/Hardware and settings used for encoding */

  "TSST", /* ID3FID_SETSUBTITLE,        */ /**< Set subtitle */

  "TXXX", /* ID3FID_USERTEXT,           */ /**< User defined text information */

  "TYER", /* ID3FID_YEAR,               */ /**< Year */

  "UFID", /* ID3FID_UNIQUEFILEID,       */ /**< Unique file identifier */

  "USER", /* ID3FID_TERMSOFUSE,         */ /**< Terms of use */

  "USLT", /* ID3FID_UNSYNCEDLYRICS,     */ /**< Unsynchronized lyric/text transcription */

  "WCOM", /* ID3FID_WWWCOMMERCIALINFO,  */ /**< Commercial information */

  "WCOP", /* ID3FID_WWWCOPYRIGHT,       */ /**< Copyright/Legal infromation */

  "WOAF", /* ID3FID_WWWAUDIOFILE,       */ /**< Official audio file webpage */

  "WOAR", /* ID3FID_WWWARTIST,          */ /**< Official artist/performer webpage */

  "WOAS", /* ID3FID_WWWAUDIOSOURCE,     */ /**< Official audio source webpage */

  "WORS", /* ID3FID_WWWRADIOPAGE,       */ /**< Official internet radio station homepage */

  "WPAY", /* ID3FID_WWWPAYMENT,         */ /**< Payment */

  "WPUB", /* ID3FID_WWWPUBLISHER,       */ /**< Official publisher webpage */

  "WXXX", /* ID3FID_WWWUSER,            */ /**< User defined URL link */

  "    ", /* ID3FID_METACRYPTO,         */ /**< Encrypted meta frame (id3v2.2.x) */

  "    ", /* ID3FID_METACOMPRESSION,    */ /**< Compressed meta frame (id3v2.2.1) */

  ">>>>"  /* ID3FID_LASTFRAMEID         */ /**< Last field placeholder */

};

//

typedef struct _tagID3v2FrameHeader

{

    TCHAR   ifh_id[4];          //???

    UCHAR   ifh_pszlength[4];   //????? TAG ???

    UCHAR   ifh_flags[2];       //????????????(2005-10-24)

  TCHAR   ifh_pad;            //?????? \0

  //?? Frame ???? ifh_pszlength(????????)+=11

  DWORD   ifh_info_length;    //ifh_pszlength???????

  DWORD   ifh_size;           //Frame ???

  DWORD   ifh_pos;            //?? Frame ???????(???????)

}ID3v2FrameHeader;

 

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//

//                  ?????? MP3ID3V1 ??

//

//////////////////////////////////////////////////////////////////////////

 

/*********************************************************************

  ????: int AudioInfo_GetMP3ID3V1(HFILE hAudioFile, MP3ID3V1INFO *pMp3ID3V1Info)

  ?    ?:

          IN: HFILE hMP3File: ??????? MP3 ??

              MP3ID3V1INFO *pMp3ID3V1Info: ??? MP3  ??????????

         OUT: 

         I/O: 

    ???: ????>=0,????<0????????? Audio_GetErrorString ??????? 

            ??? MP3 ????? ID3V1,?? bHasTag == TRUE

  ????: ?? MP3 ?? ID3V1 ??

  ?    ?: 

*********************************************************************/

int AudioInfo_GetMP3ID3V1(HFILE hMP3File, MP3ID3V1INFO *pMP3ID3V1Info)

{

  DWORD dwFileRead = 0;

  int i = 0;

  memset(pMP3ID3V1Info, 0x00, sizeof(MP3ID3V1INFO));

  //???????????>128??

  SetFilePointer(hMP3File, 0x00, 0, FILE_BEGIN);

  dwFileRead = SetFilePointer(hMP3File, 0x00, 0, FILE_END);

  if(dwFileRead<=128)

  {

    AUDIO_ERR_OUT("??????????? MP3 ??");

    return -1;

  }

  SetFilePointer(hMP3File, -128, 0, FILE_END);

  //??????128???

  ReadFile(hMP3File, pMP3ID3V1Info, 128, &dwFileRead, NULL);

  if(dwFileRead != 128)

  {

    AUDIO_ERR_OUT("??????????? MP3 ??");

    return -1;

  }

  pMP3ID3V1Info->Genre = pMP3ID3V1Info->CommentFlag;

  pMP3ID3V1Info->CommentFlag = pMP3ID3V1Info->Comment[28];

  pMP3ID3V1Info->Track = pMP3ID3V1Info->Comment[29];

  //?????? ID3V1 ??

  if(pMP3ID3V1Info->Identify[0]!='T'

    || pMP3ID3V1Info->Identify[1]!='A'

    || pMP3ID3V1Info->Identify[2]!='G')

  {

    AUDIO_ERR_OUT("?? MP3 ???? ID3V1 ??");

    pMP3ID3V1Info->bHasTag = FALSE;

    return -1;

  }

  //?? TAG ?????????????? 125 ???????????? \0

  for(i=3;i<128;i++)

  {

    if(((UCHAR*)pMP3ID3V1Info)[i] != 0x20 || ((UCHAR*)pMP3ID3V1Info)[i] != 0x00)

    {

      pMP3ID3V1Info->bHasTag = TRUE;

      break;

    }

  }

  if(!pMP3ID3V1Info->bHasTag)

  {

    AUDIO_ERR_OUT("?? MP3 ? ID3V1 ???????");

    return -1;

  }

  //??????

  //?????????

  //if(pMP3ID3V1Info->CommentFlag != 0x00)    //????????28???

  //{

  //}

  //?????? Title, Artist ?????? 0x20 ???\0

  //??????? 0x20

  //?? Title

  pMP3ID3V1Info->Title[29] = '\0';

  for(i=28;

      i>=0&&(pMP3ID3V1Info->Title[i]==0x20 || pMP3ID3V1Info->Title[i]==0x00);

      i--)

  {

    pMP3ID3V1Info->Title[i] = '\0';

  }

  //?? Artist

  pMP3ID3V1Info->Artist[29] = '\0';

  for(i=28;

      i>=0&&(pMP3ID3V1Info->Artist[i]==0x20 || pMP3ID3V1Info->Artist[i]==0x00);

      i--)

  {

    pMP3ID3V1Info->Artist[i] = '\0';

  }

  //?? Album

  pMP3ID3V1Info->Album[29] = '\0';

  for(i=28;

      i>=0&&(pMP3ID3V1Info->Album[i]==0x20 || pMP3ID3V1Info->Album[i]==0x00);

      i--)

  {

    pMP3ID3V1Info->Album[i] = '\0';

  }

  //?? ?????

  ASSERT(pMP3ID3V1Info->Genre>=0 && pMP3ID3V1Info->Genre<m_nMP3ID3v2GenreCount);

  strcpy(pMP3ID3V1Info->pszGenre, m_arrMP3ID3v2Genre[pMP3ID3V1Info->Genre]);

  return 0;

}

//////////////////////////////////////////////////////////////////////////

//

//                  ?????? MP3 ID3V2 ??

//

//////////////////////////////////////////////////////////////////////////

 

/*********************************************************************

  ????: 

  ?    ?:

          IN: 

         OUT: 

         I/O: 

    ???: 

  ????: ???? MP3 ????? ID3V2 ?????????TRUE,?????

            ??????ID3V2 ??????

  ?    ?: 

*********************************************************************/

STATIC BOOL AudioInfo_CheckMP3ID3V2(HFILE hMP3File, MP3ID3V2INFO *pMP3ID3V2Info)

{

  DWORD dwFileRead = 0;

  int i = 0;

  DWORD dwID3V2Length = 0;

  pMP3ID3V2Info->bHasTag = FALSE;

  //?? MP3 ?????? 3 ???,????? "ID3"

  ReadFile(hMP3File, (VOID*)pMP3ID3V2Info, 10, &dwFileRead, NULL);

  if(dwFileRead != 10)

  {

    return FALSE;

  }

  if( pMP3ID3V2Info->Identify[0]=='I'

    &&pMP3ID3V2Info->Identify[1]=='D'

    &&pMP3ID3V2Info->Identify[2]=='3'

    )

  {

    pMP3ID3V2Info->bHasTag = TRUE;

  }

  else

  {

    return FALSE;

  }

  //???????????????

    if(pMP3ID3V2Info->HeaderFlags&0x64==0x64)

  {

    pMP3ID3V2Info->bHasExtHeader = TRUE;

  }

    if(pMP3ID3V2Info->HeaderFlags&0x10==0x10)

  {

    pMP3ID3V2Info->bHasExtHeader = TRUE;

  }

  //?? ID3V1 ?????

    for(i=0;i<3;i++)

  {

    dwID3V2Length = dwID3V2Length + pMP3ID3V2Info->HeaderSize[i];

    dwID3V2Length = dwID3V2Length * 0x80;

  }

  dwID3V2Length = dwID3V2Length + pMP3ID3V2Info->HeaderSize[3];

  pMP3ID3V2Info->dwInfoSize = dwID3V2Length;

  return TRUE;

}

 

/*********************************************************************

  ????: 

  ?    ?:

          IN: 

         OUT: 

         I/O: 

    ???: ?? Frame ???

  ????: ?? ID3V2 ?? FrameHeader

  ?    ?: 

*********************************************************************/

STATIC UINT AudioInfo_GetFrameHeader(HFILE hMP3File,  MP3ID3V2INFO *pMP3ID3V2Info)

{

  DWORD dwFileRead = 0;

  DWORD dwFilePos = 0;

  UINT  uFrameCount = 0;

  int i = 0;

  ID3v2FrameHeader tFrmHeader = {0};

  UINT uFrameID = ID3FID_NOFRAME;

  for(dwFilePos=10; dwFilePos<pMP3ID3V2Info->dwInfoSize;)

  {

    SetFilePointer(hMP3File, dwFilePos, 0, FILE_BEGIN);

    ReadFile(hMP3File, (VOID*)&tFrmHeader, 11, &dwFileRead, NULL);

    ASSERT(dwFileRead == 11);

    dwFilePos += dwFileRead;

    if(tFrmHeader.ifh_id[0] != 0x00)

    {

      uFrameCount++;      //Frame ?? +1

      tFrmHeader.ifh_info_length = 0;

      for(i=0;i<3;i++)

      {

        tFrmHeader.ifh_info_length = tFrmHeader.ifh_info_length+tFrmHeader.ifh_pszlength[i];

        tFrmHeader.ifh_info_length = tFrmHeader.ifh_info_length*0x80;

      }

      tFrmHeader.ifh_info_length = tFrmHeader.ifh_info_length + tFrmHeader.ifh_pszlength[3];

      if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_NOFRAME], 4)==0)

      {

        uFrameID = ID3FID_NOFRAME;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_AUDIOCRYPTO], 4)==0)

      {

        uFrameID = ID3FID_AUDIOCRYPTO;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_PICTURE], 4)==0)

      {

        uFrameID = ID3FID_PICTURE;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_AUDIOSEEKPOINT], 4)==0)

      {

        uFrameID = ID3FID_AUDIOSEEKPOINT;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_COMMENT], 4)==0)

      {

        uFrameID = ID3FID_COMMENT;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_COMMERCIAL], 4)==0)

      {

        uFrameID = ID3FID_COMMERCIAL;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_CRYPTOREG], 4)==0)

      {

        uFrameID = ID3FID_CRYPTOREG;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_EQUALIZATION2], 4)==0)

      {

        uFrameID = ID3FID_EQUALIZATION2;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_EQUALIZATION], 4)==0)

      {

        uFrameID = ID3FID_EQUALIZATION;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_EVENTTIMING], 4)==0)

      {

        uFrameID = ID3FID_EVENTTIMING;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_GENERALOBJECT], 4)==0)

      {

        uFrameID = ID3FID_GENERALOBJECT;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_GROUPINGREG], 4)==0)

      {

        uFrameID = ID3FID_GROUPINGREG;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_INVOLVEDPEOPLE], 4)==0)

      {

        uFrameID = ID3FID_INVOLVEDPEOPLE;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_LINKEDINFO], 4)==0)

      {

        uFrameID = ID3FID_LINKEDINFO;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_CDID], 4)==0)

      {

        uFrameID = ID3FID_CDID;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_MPEGLOOKUP], 4)==0)

      {

        uFrameID = ID3FID_MPEGLOOKUP;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_OWNERSHIP], 4)==0)

      {

        uFrameID = ID3FID_OWNERSHIP;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_PRIVATE], 4)==0)

      {

        uFrameID = ID3FID_PRIVATE;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_PLAYCOUNTER], 4)==0)

      {

        uFrameID = ID3FID_PLAYCOUNTER;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_POPULARIMETER], 4)==0)

      {

        uFrameID = ID3FID_POPULARIMETER;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_POSITIONSYNC], 4)==0)

      {

        uFrameID = ID3FID_POSITIONSYNC;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_BUFFERSIZE], 4)==0)

      {

        uFrameID = ID3FID_BUFFERSIZE;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_VOLUMEADJ2], 4)==0)

      {

        uFrameID = ID3FID_VOLUMEADJ2;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_VOLUMEADJ], 4)==0)

      {

        uFrameID = ID3FID_VOLUMEADJ;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_REVERB], 4)==0)

      {

        uFrameID = ID3FID_REVERB;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_SEEKFRAME], 4)==0)

      {

        uFrameID = ID3FID_SEEKFRAME;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_SIGNATURE], 4)==0)

      {

        uFrameID = ID3FID_SIGNATURE;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_SYNCEDLYRICS], 4)==0)

      {

        uFrameID = ID3FID_SYNCEDLYRICS;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_SYNCEDTEMPO], 4)==0)

      {

        uFrameID = ID3FID_SYNCEDTEMPO;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_ALBUM], 4)==0)

      {

        uFrameID = ID3FID_ALBUM;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_BPM], 4)==0)

      {

        uFrameID = ID3FID_BPM;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_COMPOSER], 4)==0)

      {

        uFrameID = ID3FID_COMPOSER;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_CONTENTTYPE], 4)==0)

      {

        uFrameID = ID3FID_CONTENTTYPE;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_COPYRIGHT], 4)==0)

      {

        uFrameID = ID3FID_COPYRIGHT;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_DATE], 4)==0)

      {

        uFrameID = ID3FID_DATE;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_ENCODINGTIME], 4)==0)

      {

        uFrameID = ID3FID_ENCODINGTIME;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_PLAYLISTDELAY], 4)==0)

      {

        uFrameID = ID3FID_PLAYLISTDELAY;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_ORIGRELEASETIME], 4)==0)

      {

        uFrameID = ID3FID_ORIGRELEASETIME;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_RECORDINGTIME], 4)==0)

      {

        uFrameID = ID3FID_RECORDINGTIME;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_RELEASETIME], 4)==0)

      {

        uFrameID = ID3FID_RELEASETIME;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_TAGGINGTIME], 4)==0)

      {

        uFrameID = ID3FID_TAGGINGTIME;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_INVOLVEDPEOPLE2], 4)==0)

      {

        uFrameID = ID3FID_INVOLVEDPEOPLE2;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_ENCODEDBY], 4)==0)

      {

        uFrameID = ID3FID_ENCODEDBY;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_LYRICIST], 4)==0)

      {

        uFrameID = ID3FID_LYRICIST;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_FILETYPE], 4)==0)

      {

        uFrameID = ID3FID_FILETYPE;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_TIME], 4)==0)

      {

        uFrameID = ID3FID_TIME;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_CONTENTGROUP], 4)==0)

      {

        uFrameID = ID3FID_CONTENTGROUP;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_TITLE], 4)==0)

      {

        uFrameID = ID3FID_TITLE;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_SUBTITLE], 4)==0)

      {

        uFrameID = ID3FID_SUBTITLE;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_INITIALKEY], 4)==0)

      {

        uFrameID = ID3FID_INITIALKEY;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_LANGUAGE], 4)==0)

      {

        uFrameID = ID3FID_LANGUAGE;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_SONGLEN], 4)==0)

      {

        uFrameID = ID3FID_SONGLEN;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_MUSICIANCREDITLIST], 4)==0)

      {

        uFrameID = ID3FID_MUSICIANCREDITLIST;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_MEDIATYPE], 4)==0)

      {

        uFrameID = ID3FID_MEDIATYPE;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_MOOD], 4)==0)

      {

        uFrameID = ID3FID_MOOD;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_ORIGALBUM], 4)==0)

      {

        uFrameID = ID3FID_ORIGALBUM;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_ORIGFILENAME], 4)==0)

      {

        uFrameID = ID3FID_ORIGFILENAME;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_ORIGLYRICIST], 4)==0)

      {

        uFrameID = ID3FID_ORIGLYRICIST;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_ORIGARTIST], 4)==0)

      {

        uFrameID = ID3FID_ORIGARTIST;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_ORIGYEAR], 4)==0)

      {

        uFrameID = ID3FID_ORIGYEAR;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_FILEOWNER], 4)==0)

      {

        uFrameID = ID3FID_FILEOWNER;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_LEADARTIST], 4)==0)

      {

        uFrameID = ID3FID_LEADARTIST;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_BAND], 4)==0)

      {

        uFrameID = ID3FID_BAND;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_CONDUCTOR], 4)==0)

      {

        uFrameID = ID3FID_CONDUCTOR;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_MIXARTIST], 4)==0)

      {

        uFrameID = ID3FID_MIXARTIST;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_PARTINSET], 4)==0)

      {

        uFrameID = ID3FID_PARTINSET;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_PRODUCEDNOTICE], 4)==0)

      {

        uFrameID = ID3FID_PRODUCEDNOTICE;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_PUBLISHER], 4)==0)

      {

        uFrameID = ID3FID_PUBLISHER;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_TRACKNUM], 4)==0)

      {

        uFrameID = ID3FID_TRACKNUM;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_RECORDINGDATES], 4)==0)

      {

        uFrameID = ID3FID_RECORDINGDATES;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_NETRADIOSTATION], 4)==0)

      {

        uFrameID = ID3FID_NETRADIOSTATION;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_NETRADIOOWNER], 4)==0)

      {

        uFrameID = ID3FID_NETRADIOOWNER;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_SIZE], 4)==0)

      {

        uFrameID = ID3FID_SIZE;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_ALBUMSORTORDER], 4)==0)

      {

        uFrameID = ID3FID_ALBUMSORTORDER;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_PERFORMERSORTORDER], 4)==0)

      {

        uFrameID = ID3FID_PERFORMERSORTORDER;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_TITLESORTORDER], 4)==0)

      {

        uFrameID = ID3FID_TITLESORTORDER;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_ISRC], 4)==0)

      {

        uFrameID = ID3FID_ISRC;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_ENCODERSETTINGS], 4)==0)

      {

        uFrameID = ID3FID_ENCODERSETTINGS;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_SETSUBTITLE], 4)==0)

      {

        uFrameID = ID3FID_SETSUBTITLE;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_USERTEXT], 4)==0)

      {

        uFrameID = ID3FID_USERTEXT;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_YEAR], 4)==0)

      {

        uFrameID = ID3FID_YEAR;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_UNIQUEFILEID], 4)==0)

      {

        uFrameID = ID3FID_UNIQUEFILEID;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_TERMSOFUSE], 4)==0)

      {

        uFrameID = ID3FID_TERMSOFUSE;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_UNSYNCEDLYRICS], 4)==0)

      {

        uFrameID = ID3FID_UNSYNCEDLYRICS;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_WWWCOMMERCIALINFO], 4)==0)

      {

        uFrameID = ID3FID_WWWCOMMERCIALINFO;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_WWWCOPYRIGHT], 4)==0)

      {

        uFrameID = ID3FID_WWWCOPYRIGHT;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_WWWAUDIOFILE], 4)==0)

      {

        uFrameID = ID3FID_WWWAUDIOFILE;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_WWWARTIST], 4)==0)

      {

        uFrameID = ID3FID_WWWARTIST;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_WWWAUDIOSOURCE], 4)==0)

      {

        uFrameID = ID3FID_WWWAUDIOSOURCE;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_WWWRADIOPAGE], 4)==0)

      {

        uFrameID = ID3FID_WWWRADIOPAGE;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_WWWPAYMENT], 4)==0)

      {

        uFrameID = ID3FID_WWWPAYMENT;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_WWWPUBLISHER], 4)==0)

      {

        uFrameID = ID3FID_WWWPUBLISHER;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_WWWUSER], 4)==0)

      {

        uFrameID = ID3FID_WWWUSER;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_METACRYPTO], 4)==0)

      {

        uFrameID = ID3FID_METACRYPTO;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_METACOMPRESSION], 4)==0)

      {

        uFrameID = ID3FID_METACOMPRESSION;

      }

      else if(strncmp(tFrmHeader.ifh_id, m_pszID3V2FrameId[ID3FID_LASTFRAMEID], 4)==0)

      {

        uFrameID = ID3FID_LASTFRAMEID;

      }

      else

      {

        ASSERT(FALSE);

        uFrameID = ID3FID_LASTFRAMEID;

      }

      //?????????????????? FrameID,????????????

      pMP3ID3V2Info->ppszTagInfo[uFrameID] = malloc(tFrmHeader.ifh_info_length);

      memset(pMP3ID3V2Info->ppszTagInfo[uFrameID], 0x00, tFrmHeader.ifh_info_length);

      ReadFile(hMP3File, pMP3ID3V2Info->ppszTagInfo[uFrameID], tFrmHeader.ifh_info_length-1, &dwFileRead, NULL);

      dwFilePos += dwFileRead;

    }

  }

  return uFrameCount;

}

 

/*********************************************************************

  ????: VOID AudioInfo_MP3ID3V2Free(MP3ID3V2INFO *pMP3ID3V2Info)

  ?    ?:

          IN: MP3ID3V2INFO *pMP3ID3V2Info: ????????

         OUT: 

         I/O: 

    ???: 

  ????: ?? MP3ID3V2INFO ????,????

  ?    ?: 

*********************************************************************/

VOID AudioInfo_MP3ID3V2Free(MP3ID3V2INFO *pMP3ID3V2Info)

{

  UINT uFrameID = 0;

  ASSERT(pMP3ID3V2Info!=NULL);

  for(uFrameID=0; uFrameID<ID3FID_MAX_COUNT;uFrameID++)

  {

    if(pMP3ID3V2Info->ppszTagInfo[uFrameID]!=NULL)

    {

      free(pMP3ID3V2Info->ppszTagInfo[uFrameID]);

      pMP3ID3V2Info->ppszTagInfo[uFrameID] = NULL;

    }

  }

}

/*********************************************************************

  ????: int AudioInfo_GetMP3ID3V2(HFILE hMP3File, MP3ID3V2INFO *pMP3ID3V2Info)

  ?    ?:

          IN: HFILE hMP3File: ??????? MP3 ??

              MP3ID3V2INFO *pMp3ID3V2Info: ??? MP3  ??????????

         OUT: 

         I/O: 

    ???: ????>=0,????<0????????? Audio_GetErrorString ???????

            ??? MP3 ????? ID3V2,?? bHasTag == TRUE

  ????: ?? MP3 ?? ID3V2 ??

      ??: ??ID3V2?????,????? AudioInfo_MP3ID3V2Free(MP3ID3V2INFO *pMP3ID3V2Info)

  ?    ?: 

*********************************************************************/

int AudioInfo_GetMP3ID3V2(HFILE hMP3File, MP3ID3V2INFO *pMP3ID3V2Info)

{

  DWORD dwFileRead = 0;

  ASSERT(pMP3ID3V2Info != NULL);

  memset(pMP3ID3V2Info, 0x00, sizeof(MP3ID3V2INFO));

  SetFilePointer(hMP3File, 0x00, 0, FILE_BEGIN);

  //????????? ID3V2 Tag ??

  if(!AudioInfo_CheckMP3ID3V2(hMP3File, pMP3ID3V2Info))

  {

    ASSERT(pMP3ID3V2Info->bHasTag == FALSE);

    return -1;

  }

  //?? MP3 ?????? ID3V2 ??????????????? ID3V2 ??

  //??????? ID3V2 ?????

 

  //?????,???? ID3V2 ??? V3 ?????

  //?????,??? ExtHeader,?????????? ExtHeader

  if(pMP3ID3V2Info->bHasExtHeader)

  {

    return -1;

  }

  //?? ID3V2 FrameHeader

  AudioInfo_GetFrameHeader(hMP3File, pMP3ID3V2Info);

  return 0;

}
